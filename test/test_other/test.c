/**
	@file
	@author Florian Evaldsson
	@version 0.1
	
	@section LICENSE
	
	Copyright (c) 2015 Florian Evaldsson <florian.evaldsson@telia.com>


	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <eksparent.h>
#include "misc.h"

int main(void)
{
	intptr_t num=-34534573095;
	
	char *str=eks_int_to_string(num);
	
	printf("%s %ld\n",str,num);
	
	free(str);
	
	//test custom content
	
	EksParent *test=eks_parent_new("test", EKS_PARENT_TYPE_TEXT, NULL, NULL);
	
	eks_parent_custom_set(test,(void*)"hello there!",-1);
	eks_parent_custom_set(test,(void*)(intptr_t)123,-1);

	//printf("pos1 = %ld, pos2 = %ld\n",pos1,pos2);
	
	char *strtest=eks_parent_custom_get(test,0);
	intptr_t numtest=(intptr_t)eks_parent_custom_get(test,1);
	
	printf("value[0] = %s, value[1] = %ld\n",strtest,numtest);
	
	eks_parent_custom_set(test,(void*)"hello hi!",2);
	
	strtest=eks_parent_custom_get(test,0);
	numtest=(intptr_t)eks_parent_custom_get(test,1);
	char *newstr=strtest=eks_parent_custom_get(test,2);
	
	printf("value[0] = %s, value[1] = %ld %s\n",strtest,numtest,newstr);
	
	eks_parent_destroy(test,EKS_TRUE);
	
	//lets print that it was successful
	printf("SUCCESS!!!\n");
	
	return 0;
}