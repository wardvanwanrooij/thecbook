struct {
  /* field 4 bits wide */
  unsigned field1 :4;
  /*
   * unnamed 3 bit field
   * unnamed fields allow for padding
   */
  unsigned        :3;
  /*
   * one-bit field
   * can only be 0 or -1 in two's complement!
   */
  signed field2   :1;
  /* align next field on a storage unit */
  unsigned        :0;
  unsigned field3 :6;
} full_of_fields;
