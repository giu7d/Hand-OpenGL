# Compile the OpenGL Studies Code
# Exec. on terminal: 
# $ sh start.sh


# FILES: 
# Set files that you want to compile, like "./ex1-hello-world.cpp"
FILES="./main.cpp ./global.cpp ./bone.cpp ./bone.h ./finger.cpp ./finger.h ./thumb.cpp ./thumb.h ./hand.cpp ./hand.h"

# OUT: 
# Set the compiled program name
OUT="main" 

# Operations
COMPILE="g++ --std=c++17 $FILES -o $OUT -lglut -lGL -lGLU"
RUN="./$OUT"

# Depuration
if $COMPILE; then
  
  echo "Compiled Successful"

  if $RUN; then
    echo "Closed"
  else
    echo "Error: On running -> ./main"
  fi

else
  echo "Error: On compiling -> ./main.cpp"
fi