# so_long

Para acessar a versão em português deste README [clique aqui](https://github.com/LeonardoSabar/so_long/blob/main/README_pt_br.md).

<p align="center">
<img src="https://github.com/LeonardoSabar/so_long/blob/main/images/screen.gif" width="800px" alt="mandatory"/><br>
</p>

## Description

Project of the 42 school common core curriculum. The goal is to create a simple 2D game using the [MLX42](https://github.com/codam-coding-college/MLX42) graphic library and the ANSI C language.

This project is build for educational purposes and you are free to use it as you wish.

If you are a 42 student, feel free to use this project as a reference, but remember: ** you need to understand the code to use it ** and maybe this is not compliant with that last subject you are working on, so be careful.

### MLX42

The MLX 42 is a simple X-Window programming API in C, designed for students, suitable for beginners.

## Code style

The code style used in this project is the [Norminette](https://github.com/42School/norminette)
created by the 42 school and used in all related ANSI C projects in the context of the school.


<br>


## Installation

Before compiling the project it is necessary to install MLX42 library a guide can be found
in the [MLX42](https://github.com/codam-coding-college/MLX42) repository.


This project also uses the external library [Libft](https://github.com/LeonardoSabar/printf) and [printf]()
developed in the 42 school curriculum, to clone this project and this library use the command:

```sh
git clone --recursive git@github.com:LeonardoSabar/so_long.git
```

**<em> this command will clone the project and the Libft submodule </em>**


</br>

To compile the **mandatory** part use:
```sh
make
```

To compile the **bonus** part use:

```sh
make bonus
```

## Usage

After compiling the project, the executable file with the name **so_long** will be created, to run the game call the executable passing the map as an argument:

Example:

```sh
./so_long map.ber
```
**<em> some maps and the map used to generate the header image can be found in the maps folder </em>**


## References

* [MLX42](https://github.com/codam-coding-college/MLX42)


## Appreciation

I would like to thank the colleagues below for their assistance during the development of this project:

* [Daniel](https://github.com/DanielSurf10).

* [Liam](https://github.com/M0LH0).

* [Chrystian](https://github.com/Chrystian-Natanael).

*[Daniel Trigo](https://github.com/willtrigo).
