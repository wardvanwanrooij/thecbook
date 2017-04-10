int
small_val (void) {
      static unsigned count;
      count ++;
      return (count % 16);
}