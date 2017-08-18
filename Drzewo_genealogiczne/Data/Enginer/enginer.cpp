#include "enginer.h"
C_enginer::C_enginer() :C_sl_date(), C_sl_personalys(), C_sl_relations() {}// m_load_files(false); }
C_enginer::C_enginer(const C_enginer &enginer) : C_sl_date(enginer), C_sl_personalys(enginer), C_sl_relations(enginer) { if (this != &enginer) *this = enginer; }
C_enginer& C_enginer::operator=(const C_enginer &enginer) {
	if (this == &enginer) return *this;
	if (*this == enginer) return *this;
	V_tree = enginer.V_tree;
	i_index = enginer.i_index;
	index_value_tree = enginer.index_value_tree;
	return *this;
}
bool C_enginer::operator==(const C_enginer &enginer) {
	if (V_tree == enginer.V_tree&&i_index==enginer.i_index&&index_value_tree==enginer.index_value_tree) return true;
	return false;
}
bool C_enginer::operator!=(const C_enginer &enginer) {
	if (V_tree != enginer.V_tree&&i_index!=enginer.i_index&&index_value_tree!=enginer.index_value_tree) return true;
	return false;
}
int C_enginer::m_set_index() { return i_index; }
void C_enginer::m_get_index(int value) { i_index = value; }
C_enginer::~C_enginer() {}
int C_enginer::i_index = NULL;
void C_enginer::m_file_init(bool b_what, N_striing Data) {
	if (b_what)
	{
		Data += "\\";
		Data += f_init_file;
		std::ifstream file;
		file.open(Data.m_c_str());
		if (file.good())
		{
			int value;
			file >> value;
			m_get_index(value);
			file.close();
		}
	}
	else
	{
		Data += "\\";
		Data += f_init_file;
		std::ofstream File;
		File.open(Data.m_c_str());
		if (File.good())
		{
			Sleep(200);
			File << m_set_index();
			File.close();
		}
	}
}
void C_enginer::m_load_files(bool what) {
	if (what)
	{
		V_goverment_date.m_close();
		V_goverment_personaly.m_close();
		V_goverment_relation.m_close();
		m_printer(1);
		m_file_init(true, index_value_tree);
		m_file_date(true, index_value_tree);
		m_load_file_personaly(true, index_value_tree);
		m_load_file_relation(true, index_value_tree);
	}
	else
	{
		m_printer(1);
		m_file_init(true, "");
		m_file_date(true, "");
		m_load_file_personaly(true, "");
		m_load_file_relation(true, "");
	}
}
void C_enginer::m_save_files(bool what) {
	if (what) {
		m_printer(2);
		m_file_init(false, index_value_tree);
		Sleep(100);
		m_file_date(false, index_value_tree);
		Sleep(100);
		m_load_file_personaly(false, index_value_tree);
		Sleep(100);
		m_load_file_relation(false, index_value_tree);
	}
	else
	{
		m_printer(2);
		m_file_init(false, "");
		m_file_date(false, "");
		m_load_file_personaly(false, "");
		m_load_file_relation(false, "");
	}
}
void C_enginer::m_new_human(C_human &human) {
	if(human.m_set_id().m_set_contens().m_atoi(0, human.m_set_id().m_set_contens().m_size())==0)
		m_add_new_personaly(++i_index,human.m_set_first_name(),human.m_set_V_last_name(),human.m_set_gender());
	else
		m_add_new_personaly(human.m_set_id(), human.m_set_first_name(), human.m_set_V_last_name(), human.m_set_gender());
	m_get_new_date(i_index, human.m_set_Vdate());
}
void C_enginer::m_printer(int i) {
	switch (i)
	{
	case 1:
	{
		//system("cls");
		std::cout << "Wczytywanie danych...\n";
		break; 
	}
	case 2:
	{
	//	system("cls");
		std::cout << "Zapisywanie danych..\n";
		break;
	}
	default:
		break;
	}
}
C_human C_enginer::m_create_human(C_id id_finter) {
	int i,j;
	i = id_finter.m_set_contens().m_atoi(0, id_finter.m_set_contens().m_size() - 1);
	if (i > 0) i--;
	C_human human(id_finter);
//	if (i > V_goverment_personaly.m_size() || i > V_goverment_date.m_size() || i > V_goverment_relation.m_size()) {
//		return human;
//	}
	human.m_get_first_name(V_goverment_personaly[i].m_set_value_first_name());
	human.m_get_gender(V_goverment_personaly[i].m_set_value_gender());
		N_vektor<C_last_name> V_last = V_goverment_personaly[i].m_set_value_last_name();
		for (j = 0; j < V_last.m_size(); j++)
				human.m_get_last_name(V_last[j]);
		if (i >= 0 && i < V_goverment_date.m_size()) {
			N_vektor<C_date> V_date = V_goverment_date[i].m_set_value_V_date();
			for (j = 0; j < V_date.m_size(); j++)
				human.m_get_date(V_date[j]);
			//std::cout << V_date[0];
			//std::cout<< V_date.m_size()<<" = "<<V_goverment_date[i].m_set_value_V_date()[0]<<"\n";
		//	Sleep(2000);
		}
		//std::cout << human << "\n";
	return human;
}
void C_enginer::m_new_element(C_element &element, bool b_what) {
	C_human human(element.m_set_Human());
	if (b_what) //gdy byl dodany human
	{
		m_add_new_relations(human.m_set_id(), element.m_set_v_children(), element.m_set_v_parent(), element.m_set_v_sibling(),
			element.m_set_v_grandchildren(), element.m_set_v_grandparents(), element.m_set_v_partner(),element.m_set_v_order());
	}
	else // gdy nie byl dodany
	{
		m_new_human(human);
		m_add_new_relations(i_index, element.m_set_v_children(), element.m_set_v_parent(), element.m_set_v_sibling(),
			element.m_set_v_grandchildren(), element.m_set_v_grandparents(), element.m_set_v_partner(), element.m_set_v_order());
	}
}
C_element C_enginer::m_create_element(C_id id_finter) {
	int i,j;
	i = id_finter.m_set_contens().m_atoi(0, id_finter.m_set_contens().m_size() - 1);
	if (i > 0) i--;
	C_element element;
	if (i > V_goverment_personaly.m_size() && i > V_goverment_date.m_size() && i > V_goverment_relation.m_size())
		return element;
	C_human human = m_create_human(i + 1);
	std::cout << human << "\n";
	int zzz;
	element.m_update_human(human);
	//tu sie gdzies kraszuje 
	if (V_goverment_relation.m_size() > 0) //dziala :)
	{
		C_goverment_relation gover(this->V_goverment_relation[i]); //tu wychodzi poza vektor!!
		std::cin >> zzz;
		N_vektor<C_children> children(gover.m_set_value_children());
		N_vektor<C_parent> parent(gover.m_set_value_parent());
		N_vektor<C_partner> partner(gover.m_set_value_patner());
		N_vektor<C_grandchildren> grandc(gover.m_set_value_grandchildren());
		N_vektor<C_grandparents> grandp(gover.m_set_value_grandparents());
		N_vektor<C_sibling> sibling(gover.m_set_value_sibling());
		N_vektor<C_order> order(gover.m_set_value_order());
		//to sie niby wlacza ale nie zupelnie
		for (j = 0; j < children.m_size(); j++) {
			element.m_get_children(children[j]);
		}
		for (j = 0; j < grandc.m_size(); j++) {
			element.m_get_grandchildren(grandc[j]);
		}
		for (j = 0; j < grandp.m_size(); j++) {
			element.m_get_grandparents(grandp[j]);
		}
		for (j = 0; j < parent.m_size(); j++) {
			element.m_get_parent(parent[j]);
		}
		for (j = 0; j < partner.m_size(); j++) {
			element.m_get_partner(partner[j]);
		}
		for (j = 0; j < sibling.m_size(); j++) {
			element.m_get_sibling(sibling[j]);
		}
		for (j = 0; j < order.m_size(); j++) {
			element.m_get_order(order[j]);
		}
	}
	//dzis bede pisac!
	//std::cout << element.m_set_Human() << "test\n";
	return element;
}
C_tree C_enginer::m_create_tree(C_id id_pointer) {
	m_create_element(id_pointer);
	int i;
		std::cin >> i;
	C_tree Tree(m_create_element(id_pointer));
	Tree.m_add_id(id_pointer);
	N_vektor <C_grandparents> V_grandparents = Tree.m_set_v_grandparents();
	N_vektor <C_parent> V_parent = Tree.m_set_v_parent();
	N_vektor <C_sibling> V_sibling = Tree.m_set_v_sibling();
	N_vektor <C_partner> V_partner = Tree.m_set_v_partner();
	N_vektor<C_children> V_children = Tree.m_set_v_children();
	N_vektor<C_grandchildren> V_grandchildren = Tree.m_set_v_grandchildren();
	N_vektor <C_order> V_order = Tree.m_set_v_order();
	//int i;
	for (i = 0; i < V_grandparents.m_size(); i++)
	{
		if(i<=3)
			Tree.m_add_human(m_create_human(V_grandparents[i].m_set_id()),t_grandparent,true,i);
		else
			Tree.m_add_human(m_create_human(V_grandparents[i].m_set_id()), t_grandparent, false, 0);
	}
	for (i = 0; i < V_parent.m_size(); i++)
	{
		if(i<=1)
			Tree.m_add_human(m_create_human(V_parent[i].m_set_id()), t_parent, true, i);
		else
			Tree.m_add_human(m_create_human(V_parent[i].m_set_id()), t_parent, false, 0);
	}
	for (i = 0; i < V_sibling.m_size(); i++)
	{
		if (i <= 1)
			Tree.m_add_human(m_create_human(V_sibling[i].m_set_id()), t_sibling, true, i);
		else
			Tree.m_add_human(m_create_human(V_sibling[i].m_set_id()), t_sibling, false, 0);
	}
	for (i = 0; i < V_partner.m_size(); i++)
	{
		if (i <= 1)
			Tree.m_add_human(m_create_human(V_partner[i].m_set_id()), t_partner, true, i);
		else
			Tree.m_add_human(m_create_human(V_partner[i].m_set_id()), t_partner, false, 0);
	}
	for (i = 0; i < V_children.m_size(); i++)
	{
		if (i <= 3)
			Tree.m_add_human(m_create_human(V_children[i].m_set_id()), t_children, true, i);
		else
			Tree.m_add_human(m_create_human(V_children[i].m_set_id()), t_children, false, 0);
	}
	for (i = 0; i < V_grandchildren.m_size(); i++)
	{
		if (i <= 3)
			Tree.m_add_human(m_create_human(V_children[i].m_set_id()), t_grandchildren, true, i);
		else
			Tree.m_add_human(m_create_human(V_children[i].m_set_id()), t_grandchildren, false, 0);
	}
	for (i = 0; i < V_order.m_size(); i++)
	{
			Tree.m_add_human(m_create_human(V_order[i].m_set_id()), t_order, false, 0);
	}
	return Tree;
	//teraz tylko przetestowac
}
void C_enginer::m_create_new_location(N_striing Data) {
		m_create_file_operation(Data);
		system(op_name_bat);
}
N_vektor<N_striing> C_enginer::m_add_to_operation(bool b_what, N_vektor<N_striing> Lista_tree) {
	N_striing data;
	int i;
	bool bwhat = true;
	if (b_what)
	{
		N_striing data;
		int i;
		//wczytywanie
		std::ifstream file;
		file.open(op_list_tree);
		if (file.good())
		{
			do
			{
				data.m_clear();
				data.m_getline(file);
				if (data == f_end_file)
					return Lista_tree;
				Lista_tree.m_push_back(data);
			} while (true);
			file.close();
		}
		return Lista_tree;
	}
	//Lista_tree.m_push_back(Data);
	//zapisywanie
	else
	{
		std::ofstream files; //zmienic na prawidlowy
		files.open(op_list_tree);
		if (files.good())
		{
			for (i = 0; i < Lista_tree.m_size(); i++)
			{
				files << Lista_tree[i];
				files << std::endl;
			}
			files << f_end_file;
			files.close();
		}
		return Lista_tree;
	}
}
void C_enginer::m_create_file_operation(N_striing Data) {
	int i;
	std::ofstream file;
	file.open(op_name_bat);
	if (file.good())
	{
		for (i = 0; i < Data.m_size(); i++)
		{
			if (Data[i] == ' ')
			{
				file << "@echo off\ncd %USERPROFILE%\\.tree\n md \"" << Data << "\" \n";
				file.close();
				return;
			}
		}
		file << "@echo off\ncd %USERPROFILE%\\.tree\n md " << Data << " \n";
		file.close();
		return;
	}
}
void C_enginer::m_get_index_value_tree(N_striing data) {
	//test
//	std::cout << data;
//	Sleep(10000);
	index_value_tree = data;
	//m_load_files(true);
	m_file_init(true, index_value_tree);
}
N_striing C_enginer::m_return_value_tree() {
	return index_value_tree;
}
void C_enginer::m_update_human(C_human &human) {
	int i;
	C_id id = human.m_set_id();
	C_first_name first = human.m_set_first_name();
	N_vektor<C_last_name> Last = human.m_set_V_last_name();
	C_last_name last;
	C_gender gender = human.m_set_gender();
	m_update_personaly(id, first, Last, gender);
	N_vektor<C_date> V_date = human.m_set_Vdate();
	m_update_date(id, V_date);
	//dokonczyc dalej
}