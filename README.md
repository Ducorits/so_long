HOW TO USE:

Clone the repository

```bash
git clone https://github.com/Ducorits/mlx_base_project
```

Initialize the submodules

```bash
git submodule init
git submodule update
```

Set a new remote origin

```bash
git remote add origin <name of your repository>
git branch -M master
git push -u origin master
```

Then:

- Rename the name variable in the makefile to the name of your executable
- Rename base.h header to whatever you want. (will have to rename all references)
- Edit .gitignore to
- Profit!
