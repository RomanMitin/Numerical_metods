#include <algorithm>
#include <cmath>
#include "calc_result.h"

double get_final_v(double v, double v_check, double S_astr)
{
	return v;
	//return v + S_astr;
}

void update_ref(Reference_t& ref, double E, double S, double h, double x)
{
	std::pair<double, double> to_cmp{E, x};

	E = std::abs(E);
	S = std::abs(S);

	ref.E_max = std::max(ref.E_max, to_cmp);
	
	to_cmp.first = S;
	ref.S_max = std::max(ref.S_max, to_cmp);

	ref.S_min = std::min(ref.S_min, to_cmp);

	to_cmp.first = h;
	ref.h_max = std::max(ref.h_max, to_cmp);

	ref.h_min = std::min(ref.h_min, to_cmp);
}

