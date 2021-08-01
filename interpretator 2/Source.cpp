#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
void interpretator(std::vector<std::string>& vec_1)
{
	std::map<std::string, std::string> tstring;
	std::map<std::string, double> tint;

	for (int i = 0; i < vec_1.size(); ++i)
	{
		if (vec_1[i] == "tvit")
		{
			double a;
			std::istringstream(vec_1[i + 1]) >> a;
			tint.emplace(vec_1[i + 1], a);
			
			//else { std::cout << "sxal syntax"; }
		}
		if (vec_1[i] == "trat")
		{
			std::string str = "", tmp;
			tstring.emplace(vec_1[i + 1], str);
			if (vec_1[i + 2] == "=")
			{
				std::istringstream(vec_1[i + 3]) >> tmp;
				tstring.emplace(vec_1[i + 1], tmp);
			}
		}
		if (vec_1[i] == "=")

		{
			if (tint.count(vec_1[i - 1]) != 1 )
			{
				std::cout << "chka tenc popoxakan";
				break;
			}
			else
			{
				double tmp;
				std::istringstream(vec_1[i + 1]) >> tmp;
				tint[vec_1[i - 1]] = tmp;
			}
		}
		if (vec_1[i] == "riptt")
		{
			std::cout << tint[vec_1[i + 1]] << std::endl;
		}
		if (vec_1[i] == "ripts")
		{
			std::cout << vec_1[i + 1] << std::endl;
		}
		if (vec_1[i] == "+")
		{
			double a, b, c;
			if (tint.count(vec_1[i - 1]) != 1 && tint.count(vec_1[i + 1]) != 1)
			{
				std::istringstream(vec_1[i - 1]) >> a;
				std::istringstream(vec_1[i + 1]) >> b;
				c = a + b;
			}
			else if (tint.count(vec_1[i - 1]) != 1 && tint.count(vec_1[i + 1]) != 0)
			{
				std::istringstream(vec_1[i - 1]) >> a;
				c = a + tint[vec_1[i + 1]];
			}
			else if (tint.count(vec_1[i - 1]) == 1 && tint.count(vec_1[i + 1]) != 1)
			{
				std::istringstream(vec_1[i + 1]) >> b;
				c = tint[vec_1[i - 1]] + b;
			}
			else
			{
				c = tint[vec_1[i - 1]] + tint[vec_1[i + 1]];
			}
			if (tint.count(vec_1[i - 3]) != 1)
			{
				tint.emplace(vec_1[i - 3], c);
			}
			else
			{
				tint[vec_1[i - 3]] = c;
			}

		}
		if (vec_1[i] == "-")
		{
			double a, b, c;
			if (tint.count(vec_1[i - 1]) != 1 && tint.count(vec_1[i + 1]) != 1)
			{
				std::istringstream(vec_1[i - 1]) >> a;
				std::istringstream(vec_1[i + 1]) >> b;
				c = a - b;
			}
			else if (tint.count(vec_1[i - 1]) != 1 && tint.count(vec_1[i + 1]) != 0)
			{
				std::istringstream(vec_1[i - 1]) >> a;
				c = a - tint[vec_1[i + 1]];
			}
			else if (tint.count(vec_1[i - 1]) == 1 && tint.count(vec_1[i + 1]) != 1)
			{
				std::istringstream(vec_1[i + 1]) >> b;
				c = tint[vec_1[i - 1]] - b;
			}
			else
			{
				c = tint[vec_1[i - 1]] - tint[vec_1[i + 1]];
			}
			if (tint.count(vec_1[i-3])!=1)
			{
				tint.emplace(vec_1[i - 3], c);
			}
			else
			{
				tint[vec_1[i - 3]] = c;
			}
			
		}
		if (vec_1[i] == "/")
		{
			double a, b, c;
			if (tint.count(vec_1[i - 1]) != 1 && tint.count(vec_1[i + 1]) != 1)
			{
				std::istringstream(vec_1[i - 1]) >> a;
				std::istringstream(vec_1[i + 1]) >> b;
				c = a / b;
			}
			else if (tint.count(vec_1[i - 1]) != 1 && tint.count(vec_1[i + 1]) != 0)
			{
				std::istringstream(vec_1[i - 1]) >> a;
				c = a / tint[vec_1[i + 1]];
			}
			else if (tint.count(vec_1[i - 1]) == 1 && tint.count(vec_1[i + 1]) != 1)
			{
				std::istringstream(vec_1[i + 1]) >> b;
				c = tint[vec_1[i - 1]] / b;
			}
			else
			{
				c = tint[vec_1[i - 1]] / tint[vec_1[i + 1]];
			}
			if (tint.count(vec_1[i - 3]) != 1)
			{
				tint.emplace(vec_1[i - 3], c);
			}
			else
			{
				tint[vec_1[i - 3]] = c;
			}

		}
		if (vec_1[i] == "*")
		{
			double a, b, c;
			if (tint.count(vec_1[i - 1]) != 1 && tint.count(vec_1[i + 1]) != 1)
			{
				std::istringstream(vec_1[i - 1]) >> a;
				std::istringstream(vec_1[i + 1]) >> b;
				c = a * b;
			}
			else if (tint.count(vec_1[i - 1]) != 1 && tint.count(vec_1[i + 1]) != 0)
			{
				std::istringstream(vec_1[i - 1]) >> a;
				c = a * tint[vec_1[i + 1]];
			}
			else if (tint.count(vec_1[i - 1]) == 1 && tint.count(vec_1[i + 1]) != 1)
			{
				std::istringstream(vec_1[i + 1]) >> b;
				c = tint[vec_1[i - 1]] * b;
			}
			else
			{
				c = tint[vec_1[i - 1]] * tint[vec_1[i + 1]];
			}
			if (tint.count(vec_1[i - 3]) != 1)
			{
				tint.emplace(vec_1[i - 3], c);
			}
			else
			{
				tint[vec_1[i - 3]] = c;
			}

		}
		if (vec_1[i] == "check")
		{
			if (vec_1[i + 1] == "(" && vec_1[i+5]==")")
			{
				if (vec_1[i + 3] == ">") 
				{
					
					if (vec_1[i + 2] == vec_1[i + 4] || vec_1[i + 2] < vec_1[i + 4]) 
					{
						vec_1[i + 6] = "!";
					}
				}
				if (vec_1[i + 3] == "<")
				{
					if (vec_1[i + 2] == vec_1[i + 4] || vec_1[i + 2] > vec_1[i + 4])
					{
						vec_1[i + 6] = "!";
					}
				}
				if (vec_1[i + 3] == "=")
				{
					if (vec_1[i + 2] > vec_1[i + 4] || vec_1[i + 2] < vec_1[i + 4])
					{
						vec_1[i + 6] = "!";
					}
				}
				if (vec_1[i + 3] == "><")
				{
					if (vec_1[i + 2] == vec_1[i + 4] )
					{
						vec_1[i + 6] = "!";
					}
				}
				if (vec_1[i + 3] == ">=")
				{
					if (vec_1[i + 2] < vec_1[i + 4])
					{
						vec_1[i + 6] = "!";
					}
				}
				if (vec_1[i + 3] == "<=")
				{
					if (vec_1[i + 2] > vec_1[i + 4])
					{
						vec_1[i + 6] = "!";
					}
				}
			}
			else 
			{
				std::cout << " pakaic dir exooooo";
			}
		}
			/*if (vec_1[i] == "fra")
			{
				if (vec_1[i + 1] == "(" && vec_1[i + 5] == ")")
				{
					if (vec_1[i + 3] == ">")
					{
						double t;
						//std::istringstream(vec_1[i + 4]) >> t;
						//tint.emplace(vec_1[i + 4], t);
						if (vec_1[i + 2] > vec_1[i + 4])
						{
							while (tint[vec_1[i + 2]] > tint[vec_1[i + 4]])
							{
								std::cout << "t";
								if (tint[vec_1[i + 2]] == tint[vec_1[i + 4]])
								{
									std::cout << "tapor";
									break;
								}
							}
						}
					}
					if (vec_1[i + 3] == "<")
					{
						while (true)
						{
							if (vec_1[i + 2] == vec_1[i + 4] || vec_1[i + 2] > vec_1[i + 4])
							{
								break;
							}
						}
					}
					if (vec_1[i + 3] == "=")
					{
						while (true)
						{
							if (vec_1[i + 2] > vec_1[i + 4] || vec_1[i + 2] < vec_1[i + 4])
							{
								break;
							}
						}
					}
					if (vec_1[i + 3] == "><")
					{
						while (true)
						{
							if (vec_1[i + 2] == vec_1[i + 4])
							{
								break;
							}
						}
					}
					if (vec_1[i + 3] == ">=")
					{
						while (true)
						{
							if (vec_1[i + 2] < vec_1[i + 4])
							{
								break;
							}
						}
					}
					if (vec_1[i + 3] == "<=")
					{
						while (true)
						{
							if (vec_1[i + 2] > vec_1[i + 4])
							{
								break;
							}
						}
					}
				}
				else
				{
					std::cout << " pakaic dir exooooo";
				}
			}*/
		

	}
}
int main()
{
	std::fstream fs;
	fs.open("Source1.txt");
	char symbol;
	std::string str; 
	std::vector<std::string>vec;
	while (!fs.eof())
	{
		fs.get(symbol);
		if (symbol != ' ' && symbol != '\n')
		{
			str.push_back(symbol);

		}
		else
		{
			vec.push_back(str);
			str = "";
		}
	}
	interpretator(vec);
	/*for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << std::endl;
	}
	*/
	//std::cout << vec.size();

}
