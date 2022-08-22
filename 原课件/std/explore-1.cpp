#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

const int MaxN = 1005;

struct Pos {
	int x, y;
	inline bool operator<(const Pos &other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
	inline bool operator!=(const Pos &other) const {
		return x != other.x || y != other.y;
	}
};
struct PosEx {
	Pos block;
	Pos cell;
};

int n, m;
char map[MaxN][MaxN];
Pos start_pos;
bool vis[MaxN][MaxN];
Pos vis_block[MaxN][MaxN];

inline void step_dimension(int &block, int &cell, int delta, int size) {
	cell += delta;
	if (cell < 0) {
		block -= 1;
		cell += size;
	} else if (cell >= size) {
		block += 1;
		cell -= size;
	}
}

inline PosEx step(PosEx original, Pos vector) {
	PosEx result = original;
	step_dimension(result.block.x, result.cell.x, vector.x, n);
	step_dimension(result.block.y, result.cell.y, vector.y, m);
	return result;
}

inline bool can_walk(Pos pos) {
	return map[pos.x][pos.y] != '#';
}

bool solve() {
	for (int i = 0; i < n; ++i) {
		std::fill(vis[i], vis[i] + m, false);
	}

	static const Pos vectors[4] = {
		{1, 0}, {-1, 0}, {0, 1}, {0, -1}
	};
	std::queue<PosEx> que;
	auto push_queue = [&que](const PosEx &pos) {
		bool &vis = ::vis[pos.cell.x][pos.cell.y];
		Pos &vis_block = ::vis_block[pos.cell.x][pos.cell.y];
		if (vis) {
			return vis_block != pos.block;
		} else {
			vis = true; vis_block = pos.block;
			que.push(pos); return false;
		}
	};
	push_queue(PosEx{.block = Pos{0, 0}, .cell = start_pos});
	while (!que.empty()) {
		PosEx current_pos = que.front(); que.pop();
		for (int i = 0; i < 4; ++i) {
			PosEx next_pos = step(current_pos, vectors[i]);
			if (can_walk(next_pos.cell) && push_queue(next_pos)) return true;
		}
	}
	return false;
}

Pos find_start_pos() {
	for (int i = 0; i < n; ++i) {
		char *row = map[i];
		for (int j = 0; j < m; ++j) {
			if (row[j] == 'S') return {i, j};
		}
	}
	puts("Error");
	return {-1, -1};
}

std::vector<Pos> query_pos;
int current_query = 0;

void jump_to_query(int index) {
	while (current_query < index) {
		Pos pos = query_pos[current_query++];
		map[pos.x][pos.y] = '#';
	}
	while (current_query > index) {
		Pos pos = query_pos[--current_query];
		map[pos.x][pos.y] = '.';
	}
}

int binary_search() {
	int l = -1, r = query_pos.size();
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		jump_to_query(mid);
		if (solve()) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

int main() {
	int query_cnt;
	scanf("%d%d%d", &n, &m, &query_cnt);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}
	start_pos = find_start_pos();
	for (int i = 0; i < query_cnt; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		query_pos.push_back(Pos{x - 1, y - 1});
	}
	int index = binary_search();
	for (int i = 0; i <= query_cnt; ++i) {
		puts(i <= index ? "Yes" : "No");
	}
	return 0;
}
