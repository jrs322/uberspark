(*
	uberSpark binary generation interface
	author: amit vasudevan (amitvasudevan@acm.org)
*)

open Ustypes
open Usconfig
open Uslog
open Usextbinutils
open Usosservices
open Usuobjcollection

module Usbin =
	struct

	let log_tag = "Usbin";;


	(*--------------------------------------------------------------------------*)
	(* generate uobj collection header source file *)
	(*--------------------------------------------------------------------------*)
	let generate_uobjcoll_hdr_src () = 
			Uslog.logf log_tag Uslog.Info "Generating uobjcoll hdr source...";

			(* create uobjcoll source file *)
			let uobj_hfilename = 
					(!Usuobjcollection.o_usmf_hdr_id ^ ".hdr.c") in
			let oc = open_out uobj_hfilename in
			
			(* generate prologue *)
			Printf.fprintf oc "\n/* autogenerated uberSpark uobjcoll header */";
			Printf.fprintf oc "\n/* author: amit vasudevan (amitvasudevan@acm.org) */";
			Printf.fprintf oc "\n";
			Printf.fprintf oc "\n#include <uberspark.h>";
			Printf.fprintf oc "\n#include <usbinformat.h>";
			Printf.fprintf oc "\n";
			Printf.fprintf oc "\n";
			Printf.fprintf oc "\n__attribute__(( section(\".data\") )) __attribute__((aligned(4096))) usbinformat_uobjcoll_hdr_t uobjcoll_hdr = {";

			(* generate common header *)
			(* hdr *)
			Printf.fprintf oc "\n\t{"; 
			(*magic*)
			Printf.fprintf oc "\n\t\tUSBINFORMAT_HDR_MAGIC_UOBJCOLL,"; 
			(*num_sections*)
			Printf.fprintf oc "\n\t\t0x%08xUL," !Usuobjcollection.o_total_uobjs; 
			(*page_size*)
			Printf.fprintf oc "\n\t\t0x%08xUL," !Usconfig.page_size; 
			(*aligned_at*)
			Printf.fprintf oc "\n\t\t0x%08xUL," 0x10000; 
			(*pad_to*)
			Printf.fprintf oc "\n\t\t0x%08xUL," 0x10000; 
			(*size*)
			Printf.fprintf oc "\n\t\t%sUL," (Usconfig.get_default_uobjcoll_hdr_size()); 
			Printf.fprintf oc "\n\t},"; 
			(* load_addr *)
			Printf.fprintf oc "\n\t0x%08xULL," !Usuobjcollection.o_load_addr; 
			(* load_size *)
			Printf.fprintf oc "\n\t0x%08xULL," !Usuobjcollection.o_size; 
			
			(* generate section def list for uobjs *)
			Printf.fprintf oc "\n\t{"; 
			
			Hashtbl.iter (fun key uobj ->  
				Printf.fprintf oc "\n\t\t{"; 
				(* type *)
				Printf.fprintf oc "\n\t\t\tUSBINFORMAT_SECTION_TYPE_UOBJ,"; 
				(* prot *)
				Printf.fprintf oc "\n\t\t\tUSBINFORMAT_SECTION_PROT_RESERVED,"; 
				(* va_offset *)
				Printf.fprintf oc "\n\t\t\t0x%08xULL," (uobj#get_o_uobj_load_addr - !Usuobjcollection.o_load_addr); 
				(* file_offset *)
				Printf.fprintf oc "\n\t\t\t0x%08xULL," (uobj#get_o_uobj_load_addr - !Usuobjcollection.o_load_addr); 
				(* size *)
				Printf.fprintf oc "\n\t\t\t0x%08xULL," (uobj#get_o_uobj_size); 
				(* aligned_at *)
				Printf.fprintf oc "\n\t\t\t0x%08xUL," 0x1000; 
				(* pad_to *)
				Printf.fprintf oc "\n\t\t\t0x%08xUL," 0x1000; 
				(* reserved *)
				Printf.fprintf oc "\n\t\t\t0ULL"; 
				Printf.fprintf oc "\n\t\t},"; 
			) Usuobjcollection.uobj_hashtbl;
			
			Printf.fprintf oc "\n\t},"; 
	
			(* generate epilogue *)
			Printf.fprintf oc "\n};";
			Printf.fprintf oc "\n";
			Printf.fprintf oc "\n";

			close_out oc;

			(uobj_hfilename)
	;;


	(*--------------------------------------------------------------------------*)
	(* generate uobj collection header binary *)
	(*--------------------------------------------------------------------------*)
	let generate_uobjcoll_hdr_bin p_uobjcoll_hdr_filename = 
		Uslog.logf log_tag Uslog.Info "Generating uobjcoll hdr binary...";

		let uobjcoll_hdr_lscript_sections = ((Hashtbl.create 32) : ((int, Ustypes.section_info_t)  Hashtbl.t)) in
						Hashtbl.add uobjcoll_hdr_lscript_sections 0 
							{f_name = "data";	
								f_subsection_list = [ ".data" ];	
								usbinformat = { f_type=0; f_prot=0; f_va_offset=0; f_file_offset=0;
								f_size = int_of_string(Usconfig.get_default_uobjcoll_hdr_size ());
								f_aligned_at = !Usconfig.section_alignment; 
								f_pad_to = !Usconfig.section_alignment; 
								f_reserved = 0;
								};
							};

		
		let status = Usextbinutils.mkbin_from_cfile p_uobjcoll_hdr_filename uobjcoll_hdr_lscript_sections 
			(p_uobjcoll_hdr_filename) 0 
			(int_of_string(Usconfig.get_default_uobjcoll_hdr_size ())) in 
			if (status == false) then
				begin
						Uslog.logf log_tag Uslog.Error "in generating uobjcoll hdr binary: %s!" p_uobjcoll_hdr_filename;
						ignore(exit 1);
				end
			else
				begin
						Uslog.logf log_tag Uslog.Info "generated uobjcoll hdr binary (%s) successfully" p_uobjcoll_hdr_filename;
				end
			;


		()
	;;



	(*--------------------------------------------------------------------------*)
	(* generate binary images for a given uobj within the collection *)
	(*--------------------------------------------------------------------------*)
	let generate_uobj_bin_image p_uobj_id p_uobj = 
			Uslog.logf log_tag Uslog.Info "Proceeding to generate binary for uobj '%s'..." p_uobj_id; 


			Uslog.logf log_tag Uslog.Info "Successfully generated binary for uobj '%s'" p_uobj_id; 
		()
	;;


	(*--------------------------------------------------------------------------*)
	(* generate uobj collection binary image *)
	(*--------------------------------------------------------------------------*)
	let generate_uobjcoll_bin_image uobjcoll_bin_image_filename = 
		Uslog.logf log_tag Uslog.Info "Proceeding to generate uobjcoll binary ('%s')..." uobjcoll_bin_image_filename;


		(* TBD: generate uobj collection info table? *)

			
		(* build binaries for individidual uobjs that are part of the collection *)
		(* Usuobjcollection.build "" true; *)
		Hashtbl.iter (fun uobj_id uobj ->  
			let(rval, r_prevpath, r_curpath) = Usosservices.dir_change 
				(uobj#get_o_uobj_dir_abspathname) in
				if(rval == true) then 
					begin
						generate_uobj_bin_image uobj_id uobj;
						ignore(Usosservices.dir_change r_prevpath);
					end
				else
					begin
						Uslog.logf log_tag Uslog.Error "could not change to uobj directory: %s" (uobj#get_o_uobj_dir_abspathname);
						ignore (exit 1);
					end
				;
			
		) Usuobjcollection.uobj_hashtbl;

	
		(* debug *)
		Uslog.logf log_tag Uslog.Info "uobj collection load_addr: 0x%08x" !Usuobjcollection.o_load_addr;
		Uslog.logf log_tag Uslog.Info "uobj collection size: 0x%08x" !Usuobjcollection.o_size;

		Hashtbl.iter (fun key uobj ->  
			Uslog.logf log_tag Uslog.Info "uobj id: %s" uobj#get_o_usmf_hdr_id;
			Uslog.logf log_tag Uslog.Info "uobj path: %s" uobj#get_o_uobj_dir_abspathname;
			Uslog.logf log_tag Uslog.Info "uobj load_addr: 0x%08x" uobj#get_o_uobj_load_addr;
			Uslog.logf log_tag Uslog.Info "uobj size: 0x%08x" uobj#get_o_uobj_size;
		) Usuobjcollection.uobj_hashtbl;
	
	
		(* generate uobj collection header *)
		let uobjcoll_hdr_filename = generate_uobjcoll_hdr_src () in
			generate_uobjcoll_hdr_bin uobjcoll_hdr_filename;

		(* concatenate uobj collection header and uobjs *)
		let input_filename_list = ref [] in
		input_filename_list := !input_filename_list @ [ uobjcoll_hdr_filename ^ ".bin"];

		Hashtbl.iter (fun key uobj ->  
				input_filename_list := !input_filename_list @ [ (uobj#get_o_uobj_dir_abspathname ^ "/" ^ uobj#get_o_usmf_hdr_id ^ ".bin") ];
		) Usuobjcollection.uobj_hashtbl;

	  Usosservices.file_concat uobjcoll_bin_image_filename !input_filename_list;

		Uslog.logf log_tag Uslog.Info "Generated uobjcoll binary ('%s') successfully!" uobjcoll_bin_image_filename;

		()
	;;
														
																												
																																																								
	end
