#include "MapperMMC3.h"
#include "CPU.h"

namespace sn
{

	MapperMMC3::MapperMMC3(Cartridge &cart, std::function<void(void)> mirroring_cb) : 
	Mapper(cart, Mapper::MMC3),
	m_mirroringCallback(mirroring_cb),
	mirrormode(Horizontal),
	irqEnabled(false),
	irqPeriod(0),
	irqCounter(0)
	{
          // RESET REGISTER
		for (int i = 0; i < 8; i++)
		{
			regs[i] = 0;
		}

		prgbank3 = &cart.getROM()[cart.getROM().size() - 1 * 0x2000];

		SetBanks();
	}


	Byte MapperMMC3::readPRG(Address addr)
	{
		if (addr < 0x8000)
		{
			return prgram[addr - 0x6000];
		}
		else
              // READ BANKS PRG
			if (addr >= 0x8000 && addr <= 0x9FFF)
		{
			return *(prgbank0 + (addr & 0x1fff));
		}

		if (addr >= 0xA000 && addr <= 0xBFFF)
		{
			return *(prgbank1 + (addr & 0x1fff));
		}

		if (addr >= 0xC000 && addr <= 0xDFFF)
		{
			return *(prgbank2 + (addr & 0x1fff));
		}

		if (addr >= 0xE000 && addr <= 0xFFFF)
		{
			return *(prgbank3 + (addr & 0x1fff));
		}
	}

	Byte MapperMMC3::readCHR(Address addr)
	{
		if (addr < 0x2000)
		{
			scanline();
		}
		
           // READ BANKS CHR
		if (addr >= 0x0000 && addr <= 0x03FF)
		{
			return *(chrbank0 + (addr & 0x03ff));
		}

		if (addr >= 0x0400 && addr <= 0x07FF)
		{
			return *(chrbank1 + (addr & 0x03ff));
		}

		if (addr >= 0x0800 && addr <= 0x0BFF)
		{
			return *(chrbank2 + (addr & 0x03ff));
		}

		if (addr >= 0x0C00 && addr <= 0x0FFF)
		{

			return *(chrbank3 + (addr & 0x03ff));
		}

		if (addr >= 0x1000 && addr <= 0x13FF)
		{
			return *(chrbank4 + (addr & 0x03ff));
		}

		if (addr >= 0x1400 && addr <= 0x17FF)
		{
			return *(chrbank5 + (addr & 0x03ff));
		}

		if (addr >= 0x1800 && addr <= 0x1BFF)
		{
			return *(chrbank6 + (addr & 0x03ff));
		}

		if (addr >= 0x1C00 && addr <= 0x1FFF)
		{
			return *(chrbank7 + (addr & 0x03ff));
		}
	}

	void MapperMMC3::SetBanks()
	{
		    prgbank1 = &m_cartridge.getROM()[(regs[7] & 0x3F) * 0x2000];

		if (!(reg8000 & (1 << 6))) // PRG MODE 0
		{

			prgbank0 = &m_cartridge.getROM()[(regs[6] & 0x3F) * 0x2000];
			prgbank2 = &m_cartridge.getROM()[m_cartridge.getROM().size() - 2 * 0x2000];
		}
		else // PRG MODE 1
		{
			prgbank0 = &m_cartridge.getROM()[m_cartridge.getROM().size() - 2 * 0x2000];
			prgbank2 = &m_cartridge.getROM()[(regs[6] & 0x3F) * 0x2000];
		}

		if (!(reg8000 & (1 << 7))) // CHR MODE 0
		{
			chrbank0 = &m_cartridge.getVROM()[(regs[0] & 0xFE) * 0x0400];
			chrbank1 = &m_cartridge.getVROM()[regs[0] * 0x0400 + 0x0400];
			chrbank2 = &m_cartridge.getVROM()[(regs[1] & 0xFE) * 0x0400];
			chrbank3 = &m_cartridge.getVROM()[regs[1] * 0x0400 + 0x0400];
			chrbank4 = &m_cartridge.getVROM()[regs[2] * 0x0400];
			chrbank5 = &m_cartridge.getVROM()[regs[3] * 0x0400];
			chrbank6 = &m_cartridge.getVROM()[regs[4] * 0x0400];
			chrbank7 = &m_cartridge.getVROM()[regs[5] * 0x0400];
		}
		else // CHR MODE 1
		{
			chrbank0 = &m_cartridge.getVROM()[regs[2] * 0x0400];
			chrbank1 = &m_cartridge.getVROM()[regs[3] * 0x0400];
			chrbank2 = &m_cartridge.getVROM()[regs[4] * 0x0400];
			chrbank3 = &m_cartridge.getVROM()[regs[5] * 0x0400];
			chrbank4 = &m_cartridge.getVROM()[(regs[0] & 0xFE) * 0x0400];
			chrbank5 = &m_cartridge.getVROM()[regs[0] * 0x0800 + 0x0400];
			chrbank6 = &m_cartridge.getVROM()[(regs[1] & 0xFE) * 0x0400];
			chrbank7 = &m_cartridge.getVROM()[regs[1] * 0x0400 + 0x0400];
		}
	}



	void MapperMMC3::writePRG(Address addr, Byte value)
	{

		if (addr < 0x8000) 
		{
			 prgram[addr - 0x6000] = value; 
		}
		else if (addr & 0x8000)
		{
			switch (addr & 0xE001)
			{
			case 0x8000: { reg8000 = value; } break;

			case 0x8001: {	regs[reg8000 & 0b111] = value; } 	break;

			case 0xA000: { mirrormode = value & 1 ? Horizontal : Vertical; } m_mirroringCallback(); break;

			case 0xC000:{  irqPeriod = value; } break;

			case 0xC001:{  irqCounter = 0; }   break;

			case 0xE000: {/* m_cpu->set_irq(irqEnabled = false);*/ irqEnabled = false;} break;

			case 0xE001:{ irqEnabled = true; }  break;
			}
		SetBanks();
	}
  
  value;
return;

}

	void MapperMMC3::writeCHR(Address addr, Byte value) {}

	void MapperMMC3::scanline()
	{
		if (irqCounter == 0)
		{
			irqCounter = irqPeriod;
		}
		else
		{
			irqCounter--;
		}
        
		if ((irqEnabled && irqCounter) == 0)
		{
		   //m_cpu->set_irq(irqEnabled = true);
			irqEnabled = true;
		}

	}

	NameTableMirroring MapperMMC3::getNameTableMirroring(){ return mirrormode; }

	const Byte *MapperMMC3::getPagePtr(Address addr) {}

} // namespace sn
