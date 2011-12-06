/*
 *  Copyright 2011 Emanuel Ey <emanuel.ey@gmail.com>
 * 
 *  This file is part of matOut.
 *
 *  MatOut is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  MatOut is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with matOut.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "matOut.h"

void* mxGetPr(mxArray* inArray);

void*	mxGetPr(mxArray* inArray){
	/*
	 * Returns pointer to the first element of the mxArray's real data.
	 * NOTE: in the matlab API this functions returns a void* pointer.
	 */
	if (inArray->isStruct){
		fatal("mxGetPr(): not possible to get data pointer from a structure.\n");
	}
	
	switch(inArray->mxCLASS){
		case mxDOUBLE_CLASS:
			return(inArray->pr_double);
			break;
		case mxCHAR_CLASS:
			return(inArray->pr_char);
			break;
		default:
			fatal("mxGetPr(): data has unknown mxClass.\n");
	}
	
	return NULL;
}
