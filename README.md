# NES

A while back I decided that I wanted to write a basic NES emulator. Unfortunately, I never finished emulation of the PPU. The CPU, however, is 99.8% implemented. This project would be a great resource to anyone who is interested in writing an NES emulator, or CPU emulation in general.

This project demonstrates how opcodes are parsed by an emulator and how an emulated CPU is represented in memory.

## Usage

`nes [rom] [step]`

Using the "step" argument makes the emulator step through each instruction being emulated for verbose debugging.

### Sample Output

```
8000: a9 0a 0a	LDA #$0A

A: 0a, X: 00, Y: 00, nv-bdizc
8002: 0a	ASL A

A: 14, X: 00, Y: 00, nv-bdizc
8003: 4a	LSR A

A: 0a, X: 00, Y: 00, nv-bdizc
8004: 4a	LSR A

A: 05, X: 00, Y: 00, nv-bdizc
8005: 4a	LSR A

A: 02, X: 00, Y: 00, nv-bdizc
8006: 0a	ASL A

A: 04, X: 00, Y: 00, nv-bdizc
8007: 0a	ASL A

A: 08, X: 00, Y: 00, nv-bdizc
8008: 0a	ASL A

A: 10, X: 00, Y: 00, nv-bdizc
8009: 0a	ASL A

A: 20, X: 00, Y: 00, nv-bdizc
800a: 0a	ASL A

A: 40, X: 00, Y: 00, nv-bdizc
800b: 00	BRK
```
