/* Program to generate all r-Combinations of a set with distinct element
 * This code is a part of http://phoxis.wordpress.com/2009/10/13/allcombgen/
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int generate_combination (const char *source_string,char *combination_string);

unsigned int comb_mask = 0x00000001;
unsigned int max_mask_length;

/* Main Function, driving generate_combination() */
int
main (void)
{
  char source_string[MAX], combination_string[MAX];
  int len;

  printf ("Enter the Source String:");
  scanf ("%s", source_string);

  len = strlen (source_string);
  max_mask_length = ~(0x00000001 << len);

  printf ("\nPrinting Combinatins:\n");
  while (1)
    {
      if (generate_combination (source_string, combination_string) == FALSE)
        break;
      printf ("%s\n", combination_string);
    }
  printf ("\nfinished\n");
  return 0;
}

/*
 *  File Name     : combination.c
 *  Function Name : generate_combination
 *  Parameters    :
 *                @ (const char *) source_string
 *                @ (char *)       combination_string
 *  Return Type   : (int)
 *                    # return FALSE if no more mermutations, else return TRUE
 *  Globals       :
 *                @ (unsigned int) comb_mask
 *                    # A bitmask. Used to select unique combinations from source
 *                      string. This function increments and updates this mask
 *                      in each iteration. Each call results in a new permutation.
 *                @ (unsigned int) max_mask_length
 *                    # A bitmask. Used to control the length of masking of
 *                      comb_mask variable. This is not modified in this function.
 *                      Initilized in function main()
 *  Description   : Each call to this function generated a new combination from
 *                  the source_string and then places into combination_string
 *                  The combination is done based upon comb_mask variable. The
 *                  positions, in which comb_mask has a '1' , are only selected
 *                  from the source_string to make a combination.
 *  Note          : The combination generation is comb_mask dependent. To generate
 *                  unique combinations in each call comb_mask should not be modified
 *                  any where else, if some explicit customized combinination is to be
 *                  generated. Each bit field has a fixed length (32bit) , the combintaion
 *                  can be generated is limited to this length, in this version of code.
 *                  This function does not return the null set.
 */

int
generate_combination (const char *source_string, char *combination_string)
{
  unsigned int mask = 0x00000001;
  int s_pos = 0, c_pos = 0;

  /* Main logic */
  while ((mask & max_mask_length))
    {
      if ((comb_mask & mask))
      {
          combination_string[c_pos] = source_string[s_pos];
          c_pos++;
      }
      s_pos++;
      mask <<= 1;
    }

  /*update permutation mask */
  comb_mask++;

  /* Terminate the combination_string with NULL character */
  combination_string[c_pos] = 0;

  /* If combination_string is empty, ie. c_pos == 0 , return FALSE else return TRUE */
  return (c_pos == 0 ? FALSE : TRUE);
}
