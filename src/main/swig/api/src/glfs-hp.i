 %module glfshp
 %{
 /* Includes the header in the wrapper code */
 #include "glfs.h"
 %}
 
 /* Parse the header file to generate wrappers */
 %include "glfs.h"
 
