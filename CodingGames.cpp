#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

int main()
{
	std::map<int, int> tasks;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int J;
		int D;
		std::cin >> J >> D;


		if (tasks.find(J) == tasks.end()) { // Если еще нет задачи начинающейся в день J
			tasks[J] = D; // Создаем задачу, в этот день
		}
		else {
			if (tasks[J] > D) { // Если уже есть задача, которая начинается в день J, но на входе задача,
				//которая выполняется быстрее, то мы заменяем ее на новую
				tasks[J] = D;
			}
		}
	}


	int ans = 0;
	int timeEnd = 0;
	for (auto& task : tasks) {
		if (task.first >= timeEnd) { //Если в текущий момент никакая задача не исполняется,
			// то мы начинаем выполнять новую задачу
			ans++;
			timeEnd = task.first + task.second;
		}
		else // Если в данный момент выполняется задача
		{
			if (task.first + task.second < timeEnd) //Мы заменяем только в том случае,
				// если рассматриваемая задача заканчивается раньше, чем выполняемая
				timeEnd = task.first + task.second;
		}
	}

	std::cout << ans << std::endl;

}