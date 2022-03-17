#include "apu.h"
#include "MainBus.h"


namespace sn
{
	// Consts
	const long SAMPLE_RATE	= 96000;   // 96 KHz
	const long CPU_CLOCK	= 1789773; // NTSC 1.789773 MHz
	const size_t OUT_SIZE	= 4096;

	// Blargg Audio
	Blip_Buffer buffer;
	Nes_Apu apu;
	blip_sample_t outBuf[OUT_SIZE];
    MainBus bus;
	//double totalCycles;
	static Sound_Queue* soundQueue;


	void APU::outputsamples(const blip_sample_t* samples, size_t count)
	{
		soundQueue->write(samples, count);

	} // OutputSamples()


	// At end of CPU Frame, run APU
	void APU::step(long length )
	{
		apu.end_frame(length);
		buffer.end_frame(length);
		//totalCycles -= length;

		// Read samples out of Blip_Buffer if there are enough to fill our output buffer
		if (buffer.samples_avail() >= OUT_SIZE)
		{
			size_t count = buffer.read_samples(outBuf, OUT_SIZE);
			outputsamples(outBuf, count);
		}

	} // RunFrame()

	Byte APU::write8( long elapsed, Address address, Byte val)
	{
		apu.write_register( elapsed, address, val );
		return val;

	} // write8()

	Byte APU::read8(long elapsed)
	{
		Byte val = apu.read_status( elapsed );
		return val;

	} // read8()


	// Callback Function for playing back samples
     int dmc_read(void*, cpu_addr_t addr)
	{
		return  bus.read(addr);

	} // DMCRead()
    
	void APU::init()
	{  
		SDL_Init(SDL_INIT_AUDIO);
		soundQueue = new Sound_Queue;
		soundQueue->init(SAMPLE_RATE);

		buffer.sample_rate(SAMPLE_RATE);
		buffer.clock_rate(CPU_CLOCK);

		apu.output(&buffer);

		// Assign DMC Callback
		apu.dmc_reader(dmc_read);


	} // Init()

	void APU::reset()
	{
		apu.reset();
		buffer.clear();

	} // Reset()

} // APU

