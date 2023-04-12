<div align="center">
  <img height="150" src="https://i.imgflip.com/7fenww.gif"  />
</div>

###

<div align="center">
  v 0.1
</div>

###

<h1 align="center">catshell 📺</h1>

###

<p align="center">a simple yet elegant shell written in C 💌</p>

<div align="center">
  <img height="400" src="https://i.ibb.co/4M5NgGd/catshell.gif"  />
</div>

<br>
<p align="center">Please do note there WILL BE memory leaks </p>
<p align="center">
  All commands normally supported by your shell (included in your $PATH) shoud work and will be executed <br>
  The following builtins have been implemented :
</p>

  ```bash
  setenv / unsetenv / env
  config commands
  exit
  ```
  
 <br>
<p align="center">You can modify the aliases and startup art in the .config/init.txt file </p>
<div align="center">

  Aliases should be formated in the following manner : `alias:<alias>:<command>` <br>
  And starup_art file = `startup_art=<filepath>`
  
  The aliases can be turnt off and on by setting the `use_aliases` avlue to 0 or 1 respectively <br>
  It is not needed to recompile for the change to be effective !
 
</div>

###

<br>
<h3 align="center">Usage ⏸️</h3>
<br>

<div align="center">

  (Requires GCC to work)

  Start with : `make` to build project <br>
  you will now have a `catshell` binary <br>
  (feel free to move it where ever pleases you but move the .config and ressources folder along).
  <br>
  (you might need to `chmod +x catshell` to allow its execution)
  <br>
  <br>
  
  📺 quick tutorial:
  
  ```bash
  ./catshell # lauches the shell
  
  Control D # stops the shell while its running
  exit <value> # will exit on value, exits on 0 if not specified
  
  set use_aliases <0/1> # set for the session the use of aliases (overwirtes the config file)
  ```
  
  the rest works just like any other shell would !
  
</div>

###

<br>
<h3 align="center">Author 🫂</h3>
<div align="center">
  <a href="https://github.com/underhoney">@mathis</a> <br>
  <br>

  This project is open to contibutors for now ! (hit up my dms)
</div>

###
