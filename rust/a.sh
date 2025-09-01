gcc -c main.c -o bin/main.o
ld -o bin/main -dynamic-linker /lib64/ld-linux-x86-64.so.2 \
  $(gcc --print-file-name=crt1.o) \
  $(gcc --print-file-name=crti.o) \
  -lc bin/main.o \
  $(gcc --print-file-name=crtn.o) \
  -Tlink.ld -L/usr/local/lib/x86_64-linux-gnu \
  -L/lib/x86_64-linux-gnu \
  -L/usr/lib/x86_64-linux-gnu \
  -L/usr/lib/x86_64-linux-gnu64 \
  -L/usr/local/lib64 \
  -L/lib64 \
  -L/usr/lib64 \
  -L/usr/local/lib \
  -L/lib \
  -L/usr/lib \
  -L/usr/x86_64-linux-gnu/lib64 \
  -L/usr/x86_64-linux-gnu/lib