// MD5. This code is Public Domain
#include "md5.h"

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

void process_file(std::istream& in, const char* name) {
  md5_state md;
  md5_init(md);

  char buf[64];
  do {
    in.read(buf, sizeof(buf));
    md5_process(md, buf, in.gcount());
  }
  while(in.gcount());

  unsigned char res[16];
  md5_done(md, res);

  for(int i = 0; i != 16; ++i)
    std::printf("%02x", res[i]);
  std::printf("  %s\n", name);
}

// Emulates the basic functionality of md5sum.
int main(int argc, char** argv) {
  if(argv[1]) {
    for(char** file = argv+1; *file; ++file) {
      std::ifstream in(*file, std::ifstream::binary);
      if(in.is_open())
        process_file(in, *file);
    }
  } else {
    process_file(std::cin, "-");
  }
}
