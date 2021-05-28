# canvas-drawer

Implements a simple drawing api

TODO: Add a representative image for your project here

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake -G "Visual Studio 16 2019" ..
canvas-drawer/build $ start Draw-2D.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
canvas-drawer/build $ ../bin/Debug/draw_test
canvas-drawer/build $ ../bin/Debug/draw_art
```

*macOS*

Open terminal to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake ..
canvas-drawer/build $ make
```

To run each program from build, you would type

```
canvas-drawer/build $ ../bin/draw_test
canvas-drawer/build $ ../bin/draw_art
```

## Supported primitives

TODO: Document the custom primitives supported by your canvas class

## Results

![diagonal-line-1](https://user-images.githubusercontent.com/75322388/119922208-5f6fba00-bf3d-11eb-945a-1c4904f456e4.png)
![diagonal-line-2](https://user-images.githubusercontent.com/75322388/119922209-5f6fba00-bf3d-11eb-9c87-0d500726c6c6.png)
![horizontal-line](https://user-images.githubusercontent.com/75322388/119922210-5f6fba00-bf3d-11eb-84dd-c16e55acd19a.png)
![line-color-interpolation](https://user-images.githubusercontent.com/75322388/119922211-5f6fba00-bf3d-11eb-96ab-9ef3da743194.png)
![quad](https://user-images.githubusercontent.com/75322388/119922212-60085080-bf3d-11eb-9c4c-9cee9e456d5d.png)
![triangle](https://user-images.githubusercontent.com/75322388/119922213-60085080-bf3d-11eb-8610-7ca3d5743402.png)
![vertical-line](https://user-images.githubusercontent.com/75322388/119922214-60085080-bf3d-11eb-8497-8916860eb62c.png)

<br/> Simple unique image rendered
![arttest](https://user-images.githubusercontent.com/75322388/119922238-6a2a4f00-bf3d-11eb-9ba9-db983bb05c2d.png)

