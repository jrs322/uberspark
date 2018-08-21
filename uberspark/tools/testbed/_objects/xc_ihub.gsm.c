#include <uberspark.h>
#include <xmhf-hwm.h>

#include <xc_ihub.h>
#include <uapi_gcpustate.h>
#include <uapi_hcpustate.h>
#include <uapi_sysdata.h>
#include <uapi_slabmempgtbl.h>
#include <xh_hyperdep.h>
#include <xh_syscalllog.h>
#include <xh_ssteptrace.h>
#include <xh_aprvexec.h>


{
	"uobj-name": "xc_ihub",
	"uobj-type": "VfT_SLAB",
	"uobj-subtype": "INTERCEPT",

	"uobj-uapifunctions":[],

	"uobj-callees": "	uapi_gcpustate
						uapi_hcpustate
						uapi_sysdata
						uapi_slabmempgtbl
						xh_hyperdep
						xh_syscalllog
						xh_ssteptrace
						xc_exhub
					",

	"uobj-uapicallees":[
		{ 
			"uobj-name": "uapi_gcpustate",
			"uobj-uapifunctionid": USMF_STR(XMHF_HIC_UAPI_CPUSTATE_VMREAD), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_gcpustate",
			"uobj-uapifunctionid": USMF_STR(XMHF_HIC_UAPI_CPUSTATE_VMWRITE), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_gcpustate",
			"uobj-uapifunctionid": USMF_STR(XMHF_HIC_UAPI_CPUSTATE_GUESTGPRSREAD), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_gcpustate",
			"uobj-uapifunctionid": USMF_STR(XMHF_HIC_UAPI_CPUSTATE_GUESTGPRSWRITE), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_hcpustate",
			"uobj-uapifunctionid": USMF_STR(XMHF_HIC_UAPI_CPUSTATE_WRMSR), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_hcpustate",
			"uobj-uapifunctionid": USMF_STR(XMHF_HIC_UAPI_CPUSTATE_RDMSR), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_sysdata",
			"uobj-uapifunctionid": USMF_STR(UXMHF_UAPI_SYSDATA_E820GETMAXINDEX), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_sysdata",
			"uobj-uapifunctionid": USMF_STR(UXMHF_UAPI_SYSDATA_E820GETENTRYFORINDEX), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_slabmempgtbl",
			"uobj-uapifunctionid": USMF_STR(XMHFGEEC_UAPI_SLABMEMPGTBL_FLUSHTLB), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		}
	],	


	"uobj-resource-devices":[],

	"uobj-resource-memory":[],	

	"uobj-exportfunctions": "",


	"uobj-binary-sections":[
		{ 
			"section-name": "code",
			"section-size": "0x200000"
		},
		{ 
			"section-name": "data",
			"section-size": "0x200000"
		},
		{ 
			"section-name": "stack",
			"section-size": "0x600000"
		},
		{ 
			"section-name": "dmadata",
			"section-size": "0x200000"
		}
	],	

	
	"c-files":	"",
		
	"v-harness": []
		
	
}










