#include <uberspark.h>
#include <xmhf-hwm.h>
#include <geec_prime.h>
#include <geec_sentinel.h>
#include <uapi_slabmempgtbl.h>
#include <uapi_sysdata.h>
#include <xc_init.h>

{
	"uobj-name": "geec_prime",
	"uobj-type": "VfT_SLAB",
	"uobj-subtype": "PRIME",

	"uobj-uapifunctions":[],

	"uobj-callees": " 	geec_sentinel
						uapi_slabmempgtbl
						xc_init
						uapi_sysdata
					",

	"uobj-uapicallees":[
		{ 
			"uobj-name": "uapi_slabmempgtbl",
			"uobj-uapifunctionid": USMF_STR(XMHFGEEC_UAPI_SLABMEMPGTBL_SETENTRYFORPADDR), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_slabmempgtbl",
			"uobj-uapifunctionid": USMF_STR(XMHFGEEC_UAPI_SLABMEMPGTBL_INITMEMPGTBL), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_sysdata",
			"uobj-uapifunctionid": USMF_STR(UXMHF_UAPI_SYSDATA_E820ADDENTRY), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		}
	],	


	"uobj-resource-devices":[
		{ 
			"type": "include",
			"opt1" : USMF_STR(PCI_VENDOR_ID_XMHFGEEC),
			"opt2" : USMF_STR(PCI_DEVICE_ID_XMHFGEEC_LAPIC) 
		},
		{ 
			"type": "include",
			"opt1" : USMF_STR(PCI_VENDOR_ID_XMHFGEEC),
			"opt2" : USMF_STR(PCI_DEVICE_ID_XMHFGEEC_TXT) 
		},
		{ 
			"type": "include",
			"opt1" : USMF_STR(PCI_VENDOR_ID_XMHFGEEC),
			"opt2" : USMF_STR(PCI_DEVICE_ID_XMHFGEEC_TPM) 
		},
		{ 
			"type": "include",
			"opt1" : USMF_STR(PCI_VENDOR_ID_XMHFGEEC),
			"opt2" : USMF_STR(PCI_DEVICE_ID_XMHFGEEC_IOMMU) 
		}
	],	

	"uobj-resource-memory":[],	

	"uobj-exportfunctions": "",


	"uobj-binary-sections":[
		{ 
			"section-name": "code",
			"section-size": "0x200000"
		},
		{ 
			"section-name": "data",
			"section-size": "0x3800000"
		},
		{ 
			"section-name": "stack",
			"section-size": "0xe00000"
		},
		{ 
			"section-name": "dmadata",
			"section-size": "0x200000"
		}
	],	

	
	"c-files":	"",
		
	"v-harness": []
		
	
}



