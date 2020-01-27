![](assets/logo.png)

KScott's Corruptor. .rotpurroC s'ttocSK

## State of Production ##

Very, very unfinished.

My first wxGlade program.

## Install ##

This program is written in C++, and uses [wxWidgets][0] and
[wxGlade][1] as a GUI framework.

[0]: https://wxwidgets.org/
[1]: http://wxglade.sourceforge.net/

On most Linux distributions, you can install `base-devel` and
`wxgtk` or equivalent with your package manager.

e.g. `sudo pacman -Sy wxgtk base-devel`,
     `sudo apt install wxgtk build-essential`...

Arch has an AUR package for wxGlade, (which is what I used).

`yay -S wxglade` (or whatever AUR helper you use)

On Windows, you'll likely need to use MinGW or spend like 5
hours getting this to compile on Visual Studio or MonoDevelop.

(If you do, *please* make a pull request with the SLN! <3)

Also make sure to add wxGlade to the PATH somehow on Windows
for the Makefile to work.

It's (hopefully) as simple as typing

```
git clone https://github.com/KScottDB/kcorock.git
cd kcorock
make kcorock
```

in your shell.

## .kct File Format ##

it stands for KCorock Theme

nothing to write about it yet, nor much code relating to it,
but clues of what the implementation will be are in the file
itself.

it is just plain text, ini-alike.