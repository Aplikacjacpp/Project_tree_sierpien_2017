#include "sl_relations.h"
C_sl_relations::C_sl_relations():C_save_load() {}
C_sl_relations::C_sl_relations(const C_sl_relations & sl_relations):C_save_load(sl_relations) {
	if (this != &sl_relations) *this = sl_relations;
}
C_sl_relations& C_sl_relations::operator=(const C_sl_relations& sl_relations) {
	if (this == &sl_relations) return *this;
	if (*this == sl_relations) return *this;
	V_goverment_relation = sl_relations.V_goverment_relation;
	return *this;
}
bool C_sl_relations::operator==(const C_sl_relations& sl_relations) {
	if (V_goverment_relation == sl_relations.V_goverment_relation) return true;
	return false;
}
bool C_sl_relations::operator!=(const C_sl_relations& sl_relations) {
	if (V_goverment_relation != sl_relations.V_goverment_relation) return true;
	return false;
}
C_sl_relations::~C_sl_relations() {}
void C_sl_relations::m_load_file_relation(bool what, N_striing Data) {
	N_striing s_data,s_inline;
	int i_multiple, i, i_start, i_stop;
	if (what)
	{
		Data += "\\";
		Data += f_save_relation;
		C_goverment_relation Gover;
		std::ifstream File;
		File.open(Data.m_c_str());
		if (File.good())
		{
			do {
				s_inline.m_getline(File); //nie wiem czy bedzie dzialac
				if (s_inline == f_end_file) break;
				s_data += s_inline;
				s_inline.m_clear();
			} while (1);
			File.close();
		}
		//s_data = m_cypher_on(s_data);
		i_start = 0;
		for (i = 0; i < s_data.m_size(); i++)
		{
			if (s_data[i] == '>')
			{
				i_stop = i;
				N_striing s_help_data(s_data.m_cut(i_start, i_stop));
				s_help_data += '>';
				Gover.m_get_contens(s_help_data);
				V_goverment_relation.m_push_back(Gover);
				i_start = i_stop+1;
			} //dobrze wczytuje:)
		}
	}
	else
	{
		s_data.m_clear();
		Data += "\\";
		Data += f_save_relation;
		std::ofstream File;
		File.open(Data.m_c_str());
		if (File.good())
		{
		//	std::cout <<"zawartosc: "<< V_goverment_relation[0].m_set_contens()<<"\n";
			for (i = 0; i < V_goverment_relation.m_size(); i++)
			{
				s_data += V_goverment_relation[i].m_set_contens();
				s_data += '\n';
			}
		//	s_data = m_cypher_off(s_data);
			File << s_data;
			File << f_end_file;
			File.close();
		}
	}
}
N_striing C_sl_relations::m_cypher_on(N_striing data) { return data; }; //odszyfrowywanie
N_striing C_sl_relations::m_cypher_off(N_striing data) { return data; }; //zaszyfrowywanie
void C_sl_relations::m_add_new_relations(C_id id,N_vektor<C_children> V_children,
	N_vektor<C_parent> V_parent, N_vektor<C_sibling> V_sibling,
	N_vektor<C_grandchildren> V_grandchildren, N_vektor <C_grandparents> V_grandparents,
	N_vektor<C_partner> V_partner, N_vektor<C_order> V_order) {
	C_children children;
	C_parent parent;
	C_grandchildren grandchildren;
	C_grandparents grandparents;
	C_sibling sibling;
	C_partner partner;
	C_order order;
	int i;
	N_striing data;
	data = "<";
	data += id.m_what_type();
	data += id.m_set_contens();
	for (i = 0; i < V_parent.m_size(); i++)
	{
		parent = V_parent[i];
		data += parent.m_what_type();
		data += parent.m_get_content();
	}
	for (i = 0; i < V_children.m_size(); i++)
	{
		children = V_children[i];
		data += children.m_what_type();
		data += children.m_get_content();
	}
	for (i = 0; i < V_sibling.m_size(); i++)
	{
		sibling = V_sibling[i];
		data += sibling.m_what_type();
		data += sibling.m_get_content();
	}
	for (i = 0; i < V_grandparents.m_size(); i++)
	{
		grandparents = V_grandparents[i];
		data += grandparents.m_what_type();
		data += grandparents.m_get_content();
	}
	for (i = 0; i < V_grandchildren.m_size(); i++)
	{
		grandchildren = V_grandchildren[i];
		data += grandchildren.m_what_type();
		data += grandchildren.m_get_content();
	}
	for (i = 0; i < V_partner.m_size(); i++)
	{
		partner = V_partner[i];
		data += partner.m_what_type();
		data += partner.m_get_content();
	}
	for (i = 0; i < V_order.m_size(); i++)
	{
		order = V_order[i];
		data += order.m_what_type();
		data += order.m_get_content();
		data += k_atribut_order;
		data += order.m_get_atribut();
	}
	data += '>';
	C_goverment_relation Gover;
	Gover.m_get_contens(data);
	if (m_what(Gover.m_set_value_id()))
	{
		int i;
		if (V_goverment_relation.m_size() == 0) {
			V_goverment_relation.m_push_back(Gover);
			return;
		}
		for (i = 0; i < V_goverment_relation.m_size(); i++)
		{
			if (Gover.m_set_value_id() < V_goverment_relation[i].m_set_value_id()) {
				V_goverment_relation.m_insert(i, Gover);
				return;
			}
		}
			V_goverment_relation.m_push_back(Gover);
	}
	//std::cout << "\n\n\nVector: " << V_goverment_relation[0].m_set_contens() << "\nkoniec testu\n";
}
C_goverment_relation C_sl_relations::m_set_gover_relation(int i) {
	int j;
	for (j = 0; j < V_goverment_relation.m_size(); j++)
	{
		if (i == V_goverment_relation[i].m_set_value_id())
		{
			return V_goverment_relation[i];
		}
	}
	C_goverment_relation gover;
	return gover;
}
bool C_sl_relations::m_what(int value) {
	int i;
	for (i = 0; i < V_goverment_relation.m_size(); i++) {
		if (value == V_goverment_relation[i].m_set_value_id())
		{
			return false;
		}
	}
	return true;
}