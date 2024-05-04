/* This will force us to create a kernel entry function instead of jumping to kernel.c:0x00 */
void dummy_test_entrypoint() {
}

void main() {
  char text[] = "My CS499 Kernel";
  unsigned int text_length = sizeof(text)/sizeof(char);
  
  char* video_memory = (char*) 0xb8000;
  unsigned int i;
  for (i = 0; i < text_length; i++)
    {
      *video_memory = text[i];
      video_memory=video_memory+2; // 2 because to skip colour bytes
    }
}
