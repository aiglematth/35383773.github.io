#Auteur --> aiglematth

#Imports
from pwn import *

prog = ELF("./vuln")

addr = 0x00000000004011dd
mod  = "nop\nnop"

print("### Programme avant modification ###")
print(prog.disasm(prog.symbols["main"], 49))
print("")

prog.asm(addr, mod)

print("### Programme après modification ###")
print(prog.disasm(prog.symbols["main"], 49))

prog.save("./patch")

