/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "transfer.h"

bool_t
xdr_filebytes (XDR *xdrs, filebytes objp)
{
	register int32_t *buf;

	 if (!xdr_opaque (xdrs, objp, 1024))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_file (XDR *xdrs, file *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->name, 1024,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_filebytes (xdrs, objp->data))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbytes))
		 return FALSE;
	return TRUE;
}
