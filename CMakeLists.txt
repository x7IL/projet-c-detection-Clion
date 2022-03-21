cmake_minimum_required(VERSION 3.21)
project(dossier_jmaie C)

set(CMAKE_C_STANDARD 11)

include_directories(Projet_Detection)

add_executable(dossier_jmaie
        Projet_Detection/affichage.c
        Projet_Detection/affichage.h
        Projet_Detection/crea_struct.c
        Projet_Detection/crea_struct.h
        Projet_Detection/creation_info.c
        Projet_Detection/creation_infos.h
        Projet_Detection/main.c
        Projet_Detection/mon_string.c
        Projet_Detection/mon_string.h
        Projet_Detection/structure.h)
