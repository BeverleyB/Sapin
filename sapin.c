#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	total_width(int size)
{
  int line = 4;
  int i; //compteur de line
  int nbr_star = 1;
  int offset = 2; //nombre d'étoile perdues entre deux blocs
  int n = 0; //nombre de bloc à créer

 
  while (n < size)
    {
      i = 0;
      while (i < line)
	{
	  nbr_star = nbr_star + 2;
	  i++;
	}
      line++;
      
  if (n % 2 == 0)
    /* permet de determiner si le nombre de bloc est pair (on perd 2 étoiles à chaque bloc pair)
     */
      {
        offset = offset + 2;
      }
  nbr_star = nbr_star - offset;
  
      n++;
    }
  return (nbr_star + offset -2);

}
 
void    mon_sapin(int size)	
{
  int line = 4;
  int width = total_width(size);// largeur
  int nbr_space = width / 2;
  int space = 0;
  int cpt_space;
  int offset = 2;
  int n = 0; //compteur nombre de bloc
  int i; //compteur de lignes
  int nbr_star = 1;
  int j; //compteur des étoiles

  while (n < size)
    {
      if (n % 2 == 0 && n != 0)  // permet de determiner si le nombre de bloc est pair (on perd 2 étoiles à chaque bloc pair)
	    {
	      offset = offset + 2;
	    }
       
      i = 0;
      while(i < line)
	{
	  
	   space = nbr_space - nbr_star / 2; //car on ne compte que les espaces de gauche

	   cpt_space = 0;
	  while (cpt_space < space)
	    {
	      my_putchar(' ');
	      cpt_space++;
	    }
	  j = 0;
	  while (j < nbr_star)
	    {
	      my_putchar('*');
	      j++;
	    }
	  my_putchar('\n');
	  
	  if (i == line - 1) //pour vérifier si on est sur la dernière ligne puisque i=0
	    nbr_star = nbr_star - offset;
	  else
	    nbr_star = nbr_star + 2; //incrèmente deux étoiles à chaque ligne
	   i++;
	}
      
      line++; //incrémente une ligne de plus à chaque nouveau bloc
      n++;
    }
}

  
 void	 tronc_sapin(int size)
 {
   int nbr_space;
   int width = size; //largeur du tronc
   int height = size; //hauteur du tronc
   int i = 0; // compteur hauteur
   int j = 0; // compteur largeur
   int l = 0; // compteur espace

   if (size % 2 == 0) //check si on est dans un bloc pair
     {
       width = size + 1;
     }
  
   nbr_space = total_width(size) / 2 - (width / 2); //largeur dernière ligne - largeur du tronc / 2

   while (i < height)
     {
       i++;
       l = 0;
       while (l < nbr_space) //définit au dessus
	 {
	   my_putchar(' ');
	   l++;
	 }
       j = 0;
       while(j < width)
	 {
	   my_putchar('|');
	   j++;
	 }
       my_putchar('\n');
     }
 }




  int	main(int argc, char **argv)
{
  if(argc == 1)
  {
    write(1, "Error.\n", 7);
    return -1;
  }

   if (atoi(argv[1]) == 0)
   {
     write(1, "Error.\n", 7);
     return -1;
   }
   
 
      int size;
      size = atoi(argv[1]);

   if (size < 0)
   {
     write(1, "Error.\n", 7);
     return -1;
   }    
       mon_sapin(size);
       tronc_sapin(size);
  return 0;
}
