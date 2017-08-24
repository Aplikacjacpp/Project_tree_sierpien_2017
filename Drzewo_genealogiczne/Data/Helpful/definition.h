/***************************************************************************************************************
*"definition.h"
*
*
*
*
*
*CONTENTS:
* "Definicje header'ów klas"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     09.05.2017  Orginal design													  			Lukasz Janus
*1.1     09.07.2017  Changed a few definitions to polish lang, comments added					Mateusz Marchelewicz
****************************************************************************************************************/

#ifndef DEFINITON_H
#define DEFINITON_H

//definition from type - dane
#define n_first_name "$0"
#define n_last_name  "&0"
#define n_gender   "!0"
#define n_parent   "r0"
#define n_day   "D0"
#define n_month   "D1"
#define n_year   "D2"
#define n_id_personaly "d0"
#define n_id_data   "d0"
#define n_id_relation   "d0"
#define n_children   "r1"
#define n_sibling   "r2"
#define n_grandparent   "r3"
#define n_grandchildren   "r4"
#define n_partner "r5"
#define n_order   "r6"
#define n_gender_personaly   "~0"
#define n_gender_date   "~1"
#define n_gender_relation "~2"
//definition from type - typ
#define t_first_name   36
#define t_last_name   38 //
#define t_gender   33
#define t_parent   114
#define t_day   68
#define t_month   69
#define t_year   70
#define t_id_personaly   148
#define t_id_data   149
#define t_id_relation   157	//
#define t_children   115
#define t_sibling   116
#define t_grandparent   117
#define t_grandchildren   118
#define t_partner 119
#define t_order   120
#define t_gender_personaly   174
#define t_gender_date   175
#define t_gender_relation   183 // 
#define t_date_bristday 171
#define t_date_slubu 172
#define t_date_dead 173

//definition from file
#define f_save_data "data.save"				// zapis danych osobowych, imie itp
#define f_save_relation "relation.save"		// zapis relacji
#define f_save_date "date.save"				// zapis dat urodzenia, smierci
#define f_init_file "file."
#define f_end_file "#@#@#@#@#@#@#@#@#@"		// znak konca pliku
#define k_atribut_order '/'

//definicje from type relation
#define w_children_boy "Syn"
#define w_children_girl "Córka" 
#define w_grandchildren_boy "Wnuk" 
#define w_grandchildren_girl "Wnuczka" 
#define w_grandparents_boy "Dziadek" 
#define w_grandparents_girl "Babcia" 
#define w_parent_boy "Ojciec"
#define w_parent_girl "Matka"
#define w_partner_boy "M¹¿"
#define w_partner_girl "¯ona"  
#define w_sibling_boy "Brat"
#define w_sibling_girl "Siostra"

// parametry do interfejsu drzewa
#define p_grandparent_1 1
#define p_grandparent_2 2
#define p_grandparent_3 4
#define p_grandparent_4 8
#define p_parent_1 1
#define p_parent_2 2
#define p_sibling_1 1
#define p_sibling_2 2
#define p_partner_1 1
#define p_partner_2 2
#define p_children_1 1
#define p_children_2 2
#define p_children_3 4
#define p_children_4 8
#define p_grandchildren_1 1
#define p_grandchildren_2 2
#define p_grandchildren_3 4
#define p_grandchildren_4 8
//Dane operacyjne:
#define op_name_bat "operation.bat"
#define op_list_tree "Lista.ope"
#define op_name_catalog ".tree"
//Dane daty
#define d_date_bristday "z1"
#define d_date_slubu "z3"
#define d_date_dead  "z2"
//Dane menu:
#define M_menu_glowne 0
#define M_new_tree 1
#define M_load_tree 2
#define M_creating_new_tree 3
#define M_import_tree 4
#define M_dysplay_tree 5
#define M_edit_tree 6
#define M_export_tree 7
#define M_import_tree 8
#define M_szukanie 9
#define M_menu_tree 10
#define M_delete_human 11
#define M_add_human 90 //dla kilku wywolan
#define M_menu_relation 12
#define M_edit_relation 13
#define M_edit_human 14
#define M_lista 80 //dla kilku wywolan
#define M_exit -100 //by sie nie mylilo
//Dane listy
#define L_tree 0
#define L_human 1
#define L_dysplay 2
#define L_export 3
#endif // !DEFINITON_H
