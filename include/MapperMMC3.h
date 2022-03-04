#pragma once
#include "Mapper.h"
#include "CPU.h"

namespace sn
{

  class MapperMMC3 : public Mapper
  {
  public:
    MapperMMC3(Cartridge &cart, std::function<void(void)> mirroring_cb);

    Byte readPRG(Address addr);
    void writePRG(Address addr, Byte value);
    const Byte *getPagePtr(Address addr);
    NameTableMirroring getNameTableMirroring();
    Byte readCHR(Address addr);
    void writeCHR(Address addr, Byte value);
    void scanline();
    void SetBanks();
    CPU *m_cpu;

    private:

    NameTableMirroring mirrormode;
    
    // Set Banks & Register Banks
    Byte reg8000;
    Byte regs[8];
    Byte banks;

   // IRQ Registers
    Byte irqPeriod;
    Byte irqCounter;
    bool irqEnabled;

    // PRG BANKS 
    const Byte *prgbank0;
    const Byte *prgbank1;
    const Byte *prgbank2;
    const Byte *prgbank3;
    
    // CHR BANKS
    const Byte *chrbank0;
    const Byte *chrbank1;
    const Byte *chrbank2;
    const Byte *chrbank3;
    const Byte *chrbank4;
    const Byte *chrbank5;
    const Byte *chrbank6;
    const Byte *chrbank7;

    std::vector<Byte> prgram;
    std::vector<Byte> chram;
    
    std::function<void(void)> m_mirroringCallback;
  };

} // namespace sn
