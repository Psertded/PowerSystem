@echo off
md efi
md global
md rom
cd efi
echo templatefile>>PSEEFI.vhd
cd..
cd global
echo templatefile>>base.vhd
echo templatefile>>system_2.vhd
echo templatefile>>system_3.vhd
cd..
cd rom
md SYSBASE
cd SYSBASE
echo templatefile>>EFIROM.ROM
echo templatefile>>IOSYS.AWM
echo Finally!