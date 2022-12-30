cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME sfml_sample)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("ext/SFML/include/")	# добавляем директории
include_directories("inc/")
link_directories("ext/SFML/lib/")	

add_executable("${PROJECT_NAME}" proj_main.cpp
                                 src/obj.cpp
                                 inc/funky.hpp
		
)

											
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
						  sfml-window-s-d
						  sfml-system-s-d
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s-d
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)
file(COPY "imag/kom_3.png" DESTINATION "/")
file(COPY "imag/kom_4.png" DESTINATION "/")
file(COPY "imag/kom_5.png" DESTINATION "/")
file(COPY "imag/baack.png" DESTINATION "/")
file(COPY "imag/gas.png" DESTINATION "/")
file(COPY "imag/ship_1.png" DESTINATION "/")
file(COPY "imag/ship_2.png" DESTINATION "/")