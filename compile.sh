dd if=/dev/zero of=diskc.img bs=512 count=1000 
nasm bootload.asm
dd if=bootload of=diskc.img bs=512 conv=notrunc seek=0 
bcc -ansi -c -o kernel_c.o kernel.c
gcc -o loadFile loadFile.c

as86 -o kernel_asm.o kernel2.asm 
ld86 -o kernel -d kernel_c.o kernel_asm.o


bcc -ansi -c -o tstpr1.o  tstpr1.c 
as86 -o userlib.o userlib.asm
ld86 -d -o tstpr1 tstpr1.o userlib.o


./loadFile kernel
./loadFile message.txt


./loadFile tstpr1
java -jar ~/Downloads/simulator.jar



