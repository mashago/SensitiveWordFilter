#ifndef __SENSTIVE_WORD_FILTER_H__
#define __SENSTIVE_WORD_FILTER_H__

#include <string>
#include <map>
// #include <unordered_map>
#include <set>

struct sensitive_node_t
{

	int deep;
	bool end;
	std::map<char, sensitive_node_t *> node_map;
	typedef std::map<char, sensitive_node_t *>::iterator ITER;
	// std::unordered_map<char, sensitive_node_t *> node_map; // search faster, insert slower
	// typedef std::unordered_map<char, sensitive_node_t *>::iterator ITER;

	sensitive_node_t();
	void insert(const char *word, size_t size); // use pointer, faster
	void insert2(const std::string &word, size_t pos, size_t size); // use reference

	bool search(const char *word, size_t size); // use pointer, faster
	bool search2(const std::string &word, size_t pos, size_t size); // use reference

	const sensitive_node_t * find_node(const char *word, size_t size);

	void clear();
};

class sensitive_filter_t
{
private:
	sensitive_node_t *root;
public:
	sensitive_filter_t();
	~sensitive_filter_t();
	void load(std::set<std::string> words); // use pointer inside, faster
	void load2(std::set<std::string> words); // use reference inside

	bool find(const std::string &input); // use pointer inside, faster
	bool find2(const std::string &input); // use reference inside

	bool replace(std::string &input);
};

#endif
