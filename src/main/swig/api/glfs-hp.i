#
# copyright bradley childs bchilds@gmail.com
#
%module glfs-hp
 %{
 /* Includes the header in the wrapper code */
 #include src/glfs.h" 
 %}
 
 /* Parse the header file to generate wrappers */
 %include "glfs.h"
