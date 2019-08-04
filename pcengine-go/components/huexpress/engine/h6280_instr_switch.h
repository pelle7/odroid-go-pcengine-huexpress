{
#ifdef ODROID_DEBUG_PERF_CPU_ALL_INSTR
         ODROID_DEBUG_PERF_START()
#endif
    ODROID_DEBUG_PERF_START2(my_perf_mem_access)
    uint8_t cmd = PageR[reg_pc >> 13][reg_pc];
    ODROID_DEBUG_PERF_INCR2(my_perf_mem_access, ODROID_DEBUG_PERF_MEM_ACCESS1)
    switch (cmd)
    {
    // --- 0x00
    case 0x00:
    err = (*optable_runtime[cmd].func_exe) (); err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x01:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x02:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x03:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x04:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x05:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x06:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x07:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x08:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x09:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x0A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x0B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x0C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x0D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x0E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x0F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0x10
    case 0x10:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x11:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x12:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x13:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x14:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x15:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x16:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x17:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x18:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x19:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x1A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x1B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x1C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x1D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x1E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x1F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0x20
    case 0x20:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x21:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x22:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x23:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x24:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x25:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x26:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x27:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x28:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x29:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x2A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x2B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x2C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x2D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x2E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x2F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0x30
    case 0x30:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x31:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x32:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x33:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x34:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x35:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x36:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x37:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x38:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x39:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x3A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x3B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x3C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x3D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x3E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x3F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0x40
    case 0x40:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x41:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x42:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x43:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x44:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x45:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x46:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x47:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x48:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x49:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x4A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x4B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x4C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x4D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x4E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x4F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0x50
    case 0x50:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x51:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x52:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x53:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x54:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x55:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x56:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x57:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x58:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x59:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x5A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x5B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x5C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x5D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x5E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x5F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0x60
    case 0x60:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x61:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x62:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x63:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x64:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x65:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x66:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x67:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x68:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x69:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x6A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x6B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x6C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x6D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x6E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x6F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0x70
    case 0x70:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x71:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x72:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x73:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x74:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x75:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x76:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x77:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x78:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x79:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x7A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x7B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x7C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x7D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x7E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x7F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0x80
    case 0x80:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x81:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x82:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x83:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x84:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x85:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x86:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x87:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x88:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x89:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x8A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x8B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x8C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x8D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x8E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x8F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0x90
    case 0x90:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x91:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x92:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x93:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x94:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x95:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x96:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x97:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x98:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x99:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x9A:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x9B:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x9C:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x9D:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x9E:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0x9F:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0xA0
    case 0xA0:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xA1:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xA2:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xA3:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xA4:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xA5: // often
        // lda_zp, AM_ZP, "LDA"
        chk_flnz_8bit(reg_a = zp_operand(reg_pc + 1));
        reg_pc += 2;
        cycles += 4;
        err = 0;
        // err = (*optable_runtime[cmd].func_exe) ();
    break;
    case 0xA6:
       // ldx_zp, AM_ZP, "LDX"
      /*
      chk_flnz_8bit(reg_x = zp_operand(reg_pc + 1));
      reg_pc += 2;
      cycles += 4;
      err = 0;
      */
      err = (*optable_runtime[cmd].func_exe) ();
      break;
    case 0xA7:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xA8:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xA9:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xAA:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xAB:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xAC:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xAD:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xAE:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xAF:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0xB0
    case 0xB0:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xB1:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xB2:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xB3:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xB4:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xB5:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xB6:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xB7:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xB8:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xB9:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xBA:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xBB:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xBC:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xBD:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xBE:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xBF:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0xC0
    case 0xC0:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xC1:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xC2:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xC3:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xC4:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xC5:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xC6:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xC7:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xC8:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xC9:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xCA:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xCB:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xCC:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xCD:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xCE:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xCF:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0xD0
    case 0xD0:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xD1:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xD2:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xD3:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xD4:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xD5:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xD6:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xD7:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xD8:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xD9:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xDA:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xDB:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xDC:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xDD:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xDE:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xDF:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0xE0
    case 0xE0:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xE1:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xE2:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xE3:  // often -
        // tia, AM_XFER, "TIA"
        {
        uint16 from, to, len, alternate;
    
        reg_p &= ~FL_T;
        from = get_16bit_addr(reg_pc + 1);
        to = get_16bit_addr(reg_pc + 3);
        len = get_16bit_addr(reg_pc + 5);
        alternate = 0;
    
    #if ENABLE_TRACING_CD && defined(INLINED_ACCESSORS)
        fprintf(stderr, "Transfert from bank 0x%02x to bank 0x%02x\n",
                mmr[from >> 13], mmr[to >> 13]);
    #endif
    
        cycles += (6 * len) + 17;
        while (len-- != 0) {
            put_8bit_addr(to + alternate, get_8bit_addr(from++));
            alternate ^= 1;
        }
        reg_pc += 7;
        }
        err = 0;
        //err = (*optable_runtime[cmd].func_exe) ();
        break;
    case 0xE4:
        // cpx_zp, AM_ZP, "CPX"
        /*
        {
        uchar temp = zp_operand(reg_pc + 1);

        reg_p = (reg_p & ~(FL_N | FL_T | FL_Z | FL_C))
            | ((reg_x < temp) ? 0 : FL_C)
            | flnz_list[(uchar) (reg_x - temp)];
        reg_pc += 2;
        cycles += 4;
        }
        err = 0;
        */
        err = (*optable_runtime[cmd].func_exe) ();
        break;
    case 0xE5:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xE6:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xE7:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xE8:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xE9:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xEA:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xEB:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xEC:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xED:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xEE:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xEF:
    err = (*optable_runtime[cmd].func_exe) (); break;
    // --- 0xF0
    case 0xF0: // often
        // beq, AM_REL, "BEQ"
        reg_p &= ~FL_T;
        if (reg_p & FL_Z) {
            reg_pc += (SBYTE) imm_operand(reg_pc + 1) + 2;
            cycles += 4;
        } else {
            reg_pc += 2;
            cycles += 2;
        }
        err = 0;
        //err = (*optable_runtime[cmd].func_exe) ();
        break;
    case 0xF1:
        // sbc_zpindy, AM_ZPINDY, "SBC"
        /*
        sbc(zpindy_operand(reg_pc + 1));
        reg_pc += 2;
        cycles += 7;
        err = 0;
        */
        err = (*optable_runtime[cmd].func_exe) ();
        break;
    case 0xF2:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xF3:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xF4:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xF5:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xF6:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xF7:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xF8:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xF9:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xFA:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xFB:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xFC:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xFD:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xFE:
    err = (*optable_runtime[cmd].func_exe) (); break;
    case 0xFF:
    err = (*optable_runtime[cmd].func_exe) (); break;
   }
#ifdef ODROID_DEBUG_PERF_CPU_ALL_INSTR
         ODROID_DEBUG_PERF_INCR(0x0100 + (uint16_t)cmd)
#endif
}