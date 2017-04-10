#define TEST(x) if(!(x))\
      printf("test failed, line %d file %s\n",\
              __LINE__, __FILE__)

/**/

TEST(a != 23);

/**/