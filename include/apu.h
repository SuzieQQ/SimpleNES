#ifndef APU_H
#define APU_H

#include "Nes_Apu.h"
#include "Sound_Queue.h"

namespace sn
{
	class APU
	{
	private:
		
	public:
	// Blargg Audio
	void outputsamples(const blip_sample_t* samples, size_t count);

	// Read|Write Functions
	Byte write8(long elapsed, Address address, Byte val );
	Byte read8(long elapsed);

	// Managing APU
	void init();
	void reset();
	void step(long length );

    
    

	};
	

	
	

} // APU

#endif