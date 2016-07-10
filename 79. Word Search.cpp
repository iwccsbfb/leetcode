// 可以用非递归再写一遍
// 每个字母，遍历四个方向； 
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty() || word.empty()) return false;
		int h = board.size(), w = board[0].size();
		vector<vector<bool>> visited(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (search(board, visited, i, j, word, 0)) 
					return true;
			}
		}
		return false;
	}

	bool search(vector<vector<char>>& board, vector<vector<bool>>& visited,
		        int i, int j, string word, int start = 0) {
		int h = board.size(), w = board[0].size();
		// the order of this two cannot be changed
		if (start == word.size()) return true;
		if (i < 0 || i >= h || j < 0 || j >= w || visited[i][j]) return false;
		if (board[i][j] != word[start++]) return false;

		visited[i][j] = true;
		bool ret = (search(board, visited, i - 1, j, word, start) ||
			search(board, visited, i + 1, j, word, start) ||
			search(board, visited, i, j - 1, word, start) ||
			search(board, visited, i, j + 1, word, start));
		visited[i][j] = false;
		return ret;
	}
};
