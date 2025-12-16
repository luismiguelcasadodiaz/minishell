#!/usr/bin/bash
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/libft/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/error/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' src/ftpri/Makefile
sed -i -e '/-fsanitize/ s/-fsanitize/#-fsanitize/' Makefile
