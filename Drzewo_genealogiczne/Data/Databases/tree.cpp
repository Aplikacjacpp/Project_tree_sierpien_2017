#include "tree.h"
C_tree::C_tree():C_element() {
	int i;
	C_id id(0);
	for (i = 0; i < 4; i++)
	{
		C_human h(id);
		V_human_grandchildren.m_push_back(h);
		V_human_grandparent.m_push_back(h);
		V_human_children.m_push_back(h);
	}
	for (i = 0; i < 2; i++)
	{
		C_human h(id);
		V_human_parent.m_push_back(h);
		V_human_sibling.m_push_back(h);
		V_human_partner.m_push_back(h);
	}
}
C_tree::C_tree(const C_element &element):C_element(element) {
	int i;
	C_id id(0);
	for (i = 0; i < 4; i++)
	{
		C_human h(id);
		V_human_grandchildren.m_push_back(h);
		V_human_grandparent.m_push_back(h);
		V_human_children.m_push_back(h);
	}
	for (i = 0; i < 2; i++)
	{
		C_human h(id);
		V_human_parent.m_push_back(h);
		V_human_sibling.m_push_back(h);
		V_human_partner.m_push_back(h);
	}
}
C_tree::C_tree(const C_human &human):C_element(human) {
	int i;
	C_id id(0);
	for (i = 0; i < 4; i++)
	{
		C_human h(id);
		V_human_grandchildren.m_push_back(h);
		V_human_grandparent.m_push_back(h);
		V_human_children.m_push_back(h);
	}
	for (i = 0; i < 2; i++)
	{
		C_human h(id);
		V_human_parent.m_push_back(h);
		V_human_sibling.m_push_back(h);
		V_human_partner.m_push_back(h);
	}
}
C_tree::C_tree(const C_tree &tree):C_element(tree) { if (this != &tree) *this = tree; }
C_tree& C_tree::operator=(const C_tree &tree) {
	if (this == &tree) return *this;
	if (*this == tree) return *this;
	V_human_grandchildren = tree.V_human_grandchildren;
	V_human_grandparent = tree.V_human_grandparent;
	V_human_children = tree.V_human_children;
	V_human_parent = tree.V_human_parent;
	V_human_partner = tree.V_human_partner;
	V_human_sibling = tree.V_human_sibling;
	V_human_order = tree.V_human_order;
	return *this;
}
bool C_tree::operator==(const C_tree &tree) {
	if (V_human_grandchildren == tree.V_human_grandchildren&&
	V_human_grandparent == tree.V_human_grandparent&&
	V_human_children == tree.V_human_children&&
	V_human_parent == tree.V_human_parent&&
	V_human_partner == tree.V_human_partner&&
	V_human_sibling == tree.V_human_sibling&&
	V_human_order == tree.V_human_order) return true;
	return false;
}
bool C_tree::operator!=(const C_tree &tree) {
	if (V_human_grandchildren != tree.V_human_grandchildren&&
		V_human_grandparent != tree.V_human_grandparent&&
		V_human_children != tree.V_human_children&&
		V_human_parent != tree.V_human_parent&&
		V_human_partner != tree.V_human_partner&&
		V_human_sibling != tree.V_human_sibling&&
		V_human_order != tree.V_human_order) return true;
	return false;
}
C_tree::~C_tree() {}
void C_tree::m_add_human(C_human &h, int data, bool bwhat, int ivalue) {
	if (bwhat)
	{
		switch (data)
		{
		case t_children:
		{
			V_human_children.m_erase(ivalue);
			V_human_children.m_insert(ivalue,h);
			break;
		}
		case t_grandchildren:
		{
			V_human_children.m_erase(ivalue);
			V_human_grandchildren.m_insert(ivalue,h);
			break;
		}
		case t_grandparent:
		{
			V_human_children.m_erase(ivalue);
			V_human_grandparent.m_insert(ivalue,h);
			break;
		}
		case t_parent:
		{
			V_human_children.m_erase(ivalue);
			V_human_parent.m_insert(ivalue,h);
			break;
		}
		case t_partner:
		{
			V_human_children.m_erase(ivalue);
			V_human_partner.m_insert(ivalue,h);
			break;
		}
		case t_sibling:
		{
			V_human_children.m_erase(ivalue);
			V_human_sibling.m_insert(ivalue,h);
			break;
		}
		case t_order:
		{
			V_human_children.m_erase(ivalue);
			V_human_order.m_insert(ivalue,h);
			break;
		}
		default:
			break;
		}
	}
	else
	{
		switch (data)
		{
		case t_children:
		{
			V_human_children.m_push_back(h);
			break;
		}
		case t_grandchildren:
		{
			V_human_grandchildren.m_push_back(h);
			break;
		}
		case t_grandparent:
		{
			V_human_grandparent.m_push_back(h);
			break;
		}
		case t_parent:
		{
			V_human_parent.m_push_back(h);
			break;
		}
		case t_partner:
		{
			V_human_partner.m_push_back(h);
			break;
		}
		case t_sibling:
		{
			V_human_sibling.m_push_back(h);
			break;
		}
		case t_order:
		{
			V_human_order.m_push_back(h);
			break;
		}
		default:
			break;
		}
	}
}
void C_tree::m_update_human(C_human &h, int data, int ivalue) {

	switch (data)
	{
	case t_children:
	{
		V_human_children.m_erase(ivalue);
		V_human_children.m_insert(ivalue,h);
		break;
	}
	case t_grandchildren:
	{
		V_human_grandchildren.m_erase(ivalue);
		V_human_grandchildren.m_insert(ivalue, h);
		break;
	}
	case t_grandparent:
	{
		V_human_grandparent.m_erase(ivalue);
		V_human_grandparent.m_insert(ivalue, h);
		break;
	}
	case t_parent:
	{
		V_human_parent.m_erase(ivalue);
		V_human_parent.m_insert(ivalue, h);
		break;
	}
	case t_partner:
	{
		V_human_partner.m_insert(ivalue, h);
		V_human_partner.m_insert(ivalue, h);
		break;
	}
	case t_sibling:
	{
		V_human_sibling.m_erase(ivalue);
		V_human_sibling.m_insert(ivalue, h);
		break;
	}
	case t_order:
	{
		V_human_order.m_erase(ivalue);
		V_human_order.m_insert(ivalue, h);
		break;
	}
	default:
		break;
	}
}
void C_tree::m_delete_human(C_human &h, int data, int ivalue) {
	switch (data)
	{
	case t_children:
	{
		V_human_children.m_erase(ivalue);
		break;
	}
	case t_grandchildren:
	{
		V_human_grandchildren.m_erase(ivalue);
		break;
	}
	case t_grandparent:
	{
		V_human_grandparent.m_erase(ivalue);
		break;
	}
	case t_parent:
	{
		V_human_parent.m_erase(ivalue);
		break;
	}
	case t_partner:
	{
		V_human_partner.m_erase(ivalue);
		break;
	}
	case t_sibling:
	{
		V_human_sibling.m_erase(ivalue);
		break;
	}
	case t_order:
	{
		V_human_order.m_erase(ivalue);
		break;
	}
	default:
		break;
	}
}
void C_tree::m_delete_human(C_human &h, int data) {
	switch (data)
	{
	case t_children:
	{
		V_human_children.m_close();
		break;
	}
	case t_grandchildren:
	{
		V_human_grandchildren.m_close();
		break;
	}
	case t_grandparent:
	{
		V_human_grandparent.m_close();
		break;
	}
	case t_parent:
	{
		V_human_parent.m_close();
		break;
	}
	case t_partner:
	{
		V_human_partner.m_close();
		break;
	}
	case t_sibling:
	{
		V_human_sibling.m_close();
		break;
	}
	case t_order:
	{
		V_human_order.m_close();
		break;
	}
	default:
		break;
	}
}
void C_tree::m_add_id(const C_id &id) {
	ID_tree = id;
}
C_id C_tree::m_get_id() {
	return ID_tree;
}
C_human C_tree::m_get_human(int data, int ivalue) {
	switch (data)
	{
	case t_children:
	{
		return V_human_children[ivalue];
	}
	case t_grandchildren:
	{
		return V_human_grandchildren[ivalue];
	}
	case t_grandparent:
	{
		return V_human_grandparent[ivalue];
	}
	case t_parent:
	{
		return V_human_parent[ivalue];
	}
	case t_partner:
	{
		return V_human_partner[ivalue];
	}
	case t_sibling:
	{
		return V_human_sibling[ivalue];
	}
	case t_order:
	{
		return V_human_order[ivalue];
	}
	default:
		break;
	}
}
C_human C_tree::m_get_index_human() {
	return this->Human;
}
std::ostream& operator<<(std::ostream& is, const C_tree &tree) { //glowny interfejs drzewa
	C_tree T = const_cast<C_tree&> (tree);
	int i;
	int value;
	value = 0;
		for (i = 0; i < T.V_human_grandparent.m_size(); i++)
		{
			is << T.V_human_grandparent[i].m_short_interface_personaly()+"\t";
			is<<T.V_human_grandparent[i].m_short_interface_date()+"\t";
			if (T.V_human_grandparent[i].m_short_interface_personaly().m_size() > 1 ||
				T.V_human_grandparent[i].m_short_interface_date().m_size() > 1) {
				switch (i)
				{
				case 1:
					value += p_grandparent_1;
					break;
				case 2:
					value += p_grandparent_2;
					break;
				case 3:
					value += p_grandparent_3;
					break;
				case 4:
					value += p_grandparent_4;
					break;
				default:
					break;
				}
			}
		}
		switch (value)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			break;
		}
		case 13:
		{
			break;
		}
		case 14:
		{
			break;
		}
		case 15:
		{
			break;
		}
		default:
			break;
		}
		//rysowanie lini
		value = 0;
		for (i = 0; i < T.V_human_parent.m_size(); i++)
		{
			is<<T.V_human_parent[i].m_short_interface_personaly()+"\t";
			is<<T.V_human_parent[i].m_short_interface_date()+"\t";
			if (T.V_human_parent[i].m_short_interface_personaly().m_size() > 1 ||
				T.V_human_parent[i].m_short_interface_date().m_size() > 1) {
				switch (i)
				{
				case 1:
					value += p_parent_1;
					break;
				case 2:
					value += p_parent_2;
					break;
				default:
					break;
				}
			}
		}
		switch (value)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		default:
			break;
		}
		//rysowanie lini
		value = 0;
		for (i = 0; i < T.V_human_sibling.m_size(); i++)
		{
			is<<T.V_human_sibling[i].m_short_interface_personaly()+"\t";
			is<<T.V_human_sibling[i].m_short_interface_date()+"\t";
			if (T.V_human_sibling[i].m_short_interface_personaly().m_size() > 1 ||
				T.V_human_sibling[i].m_short_interface_date().m_size() > 1) {
				switch (i)
				{
				case 1:
					value += p_sibling_1;
					break;
				case 2:
					value += p_sibling_2;
					break;
				default:
					break;
				}
			}
		}
		switch (value)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		default:
			break;
		}
		//rysowanie lini
		is << T.Human.m_short_interface_personaly()+"\t";
		is<<T.Human.m_short_interface_date()+"\t";
		value = 0;
		for (i = 0; i < T.V_human_partner.m_size(); i++) {
			if (T.V_human_partner[i].m_short_interface_personaly().m_size() > 1 ||
				T.V_human_partner[i].m_short_interface_date().m_size() > 1) {
				switch (i)
				{
				case 1:
					value += p_partner_1;
					break;
				case 2:
					value += p_partner_2;
					break;
				default:
					break;
				}
			}
		}
		switch (value)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		default:
			break;
		}
		for (i = 0; i < T.V_human_partner.m_size(); i++)
		{
			is<<T.V_human_partner[i].m_short_interface_personaly()+"\t";
			is<<T.V_human_partner[i].m_short_interface_date()+"\t";
		}
		value = 0;
		for (i = 0; i < T.V_human_children.m_size(); i++) {
			if (T.V_human_children[i].m_short_interface_personaly().m_size() > 1 ||
				T.V_human_children[i].m_short_interface_date().m_size() > 1) {
				switch (i)
				{
				case 1:
					value += p_children_1;
					break;
				case 2:
					value += p_children_2;
					break;
				case 3:
					value += p_children_3;
					break;
				case 4:
					value += p_children_4;
					break;
				default:
					break;
				}
			}
		}
		switch (value)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		default:
			break;
		}
		//rysowanie lini
		for (i = 0; i < T.V_human_children.m_size(); i++)
		{
			is<<T.V_human_children[i].m_short_interface_personaly()+"\t";
			is<<T.V_human_children[i].m_short_interface_date()+"\t";
		}
		value = 0;
		for (i = 0; i < T.V_human_grandchildren.m_size(); i++) {
			if (T.V_human_grandchildren[i].m_short_interface_personaly().m_size() > 1 ||
				T.V_human_grandchildren[i].m_short_interface_date().m_size() > 1) {
				switch (i)
				{
				case 1:
					value += p_grandchildren_1;
					break;
				case 2:
					value += p_grandchildren_2;
					break;
				case 3:
					value += p_grandchildren_3;
					break;
				case 4:
					value += p_grandchildren_4;
					break;
				default:
					break;
				}
			}
		}
		switch (value)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			break;
		}
		case 13:
		{
			break;
		}
		case 14:
		{
			break;
		}
		case 15:
		{
			break;
		}
		default:
			break;
		}
		//rysowanie lini
		for (i = 0; i < T.V_human_grandchildren.m_size(); i++)
		{
			is<<T.V_human_grandchildren[i].m_short_interface_personaly()+"\t";
			is<<T.V_human_grandchildren[i].m_short_interface_date()+"\t";
		}
	
		//rysowanie lini
		return is;
}
	