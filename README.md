<p align="center">
	<img src="https://img.shields.io/github/last-commit/marianaobmorais/ft_printf?color=%2312bab9&style=flat-square"/>
</p>

# ft_printf

#### Finished in 2024-05-02

## About

 The goal of this project is pretty straightforward: to recode printf() function.  
 This function was added to my library [libft](https://github.com/marianaobmorais/libft/).

The mandatory conversions to be implemented:  
**%c** Prints a single character.  
**%s** Prints a string (as defined by the common C convention).  
**%p** The void * pointer argument has to be printed in hexadecimal format.  
**%d** Prints a decimal (base 10) number.  
**%i** Prints an integer in base 10.  
**%u** Prints an unsigned decimal (base 10) number.  
**%x** Prints a number in hexadecimal (base 16) lowercase format.  
**%X** Prints a number in hexadecimal (base 16) uppercase format.  
**%%** Prints a percent sign.  

The buffer management of the original printf() was not implemented.

## Build

 Clone the repository: 
 ```shell
git clone https://github.com/marianaobmorais/ft_printf.git
```
 Enter the clonned directory:
 ```shell
cd ft_printf
```
Finally, run `make` to compile the libftprintf.a:
```shell
make
```

## Usage

Add `#include "<path>/libftprintf.h"` to your source file that is using functions to the library.  
Substitute `<path>` for the path to the ft_printf folder: 

```c
#include "./ft_printf/libftprintf.h"

int  main(void)
{
	char *string;
	string = "Hello, World!";
	ft_printf("%s\n", string);
	return (0);
}
```

Include the static library `libftprintf.a` to your project folder and when compiling your project:

```shell
cc -Wall -Werror -Wextra your_project.c libftprintf.a
```

## The Norm

This project is written in accordance to the 42 School's "The Norm" (_Version 4_). To review the Norm, [click here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).

## Contributions

If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

## Message to students

If you are searching resources to learn more about your own ft_printf, I encourage you to turn to your peers and the function manuals. Do not implement any code you do not understand and cannot code from scratch.
