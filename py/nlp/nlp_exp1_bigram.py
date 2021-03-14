import re
import jieba

def PlusOne(test):
	# 初始化概率为1
	p = 1
	# 对给定语句进行分词
	words_list = list(jieba.cut(test))
	print(words_list)
	# last_word表示上个一元语法，初始化为<BOS>
	last_word = '<BOS>'
	# V为词汇表单词的个数，等于dict1中的元素个数减去2(即去掉'<BOS>'和'<EOS>')
	V = len(dict1) - 2
	for word in words_list:
		# 计算概率p
		p *= ((dict2.get(last_word + word, 0) + 1) / (dict1.get(last_word, 0) + V))
		# 上个一元语法更新为该一元语法
		last_word = word
	# 计算概率p
	p *= ((dict2.get(last_word + '<EOS>', 0) + 1) / (dict1.get(last_word, 0) + V))
	# 打印概率
	print('p('+test+') =',p)

def BigramTrain(fileName):
	with open(fileName) as f:
		# dict1存一元语法频数，dict2存二元语法频数
		dict1 = {}
		dict2 = {}
		for line in f.readlines():
			# 将每一段话切分成单个句子，存储在列表中
			sentences = re.split(r"(，/w |。/w |；/w|？/w|！/w|：/w)", line.strip())
			# 防止只有一句话
			sentences.append("")
			# 将标点也添加到句子末尾
			sentences = ["".join(i) for i in zip(sentences[0::2], sentences[1::2])]
			# 去除空句子
			sentences = list(filter(None, sentences))
			for sentence in sentences:
				# 将每一个句子切分成单个一元语法，存储在列表中
				words_list = sentence.strip().split()
				# last_word表示上个一元语法，初始化为<BOS>
				last_word = '<BOS>'
				# '<BOS>'和'<EOS>'的频数+1
				dict1['<BOS>'] = dict1.get('<BOS>', 0) + 1
				dict1['<EOS>'] = dict1.get('<EOS>', 0) + 1
				for word in words_list:
					# 一元语法只取'/'前面的部分
					words = word.split('/')
					word = words[0]
					# 如果一元语法以'['开头，则去掉'['
					if(word[0] == '['):
						word = word[1:]
					# 该一元语法频数+1
					dict1[word] = dict1.get(word, 0) + 1
					# 上个一元语法和该一元语法组成的二元语法频数+1
					dict2[last_word + word] = dict2.get(last_word + word, 0) + 1
					# 上个一元语法更新为该一元语法
					last_word = word
				# 最后一个一元语法和'<EOS>'组成的二元语法频数+1
				dict2[last_word + '<EOS>'] = dict2.get(last_word + '<EOS>', 0) + 1
	return dict1, dict2

if __name__ == '__main__':
	# 调用Bigram语言模型的训练函数
	dict1, dict2 = BigramTrain("199801.txt")
	# 打印一元语法字典和二元语法字典中的元素个数
	print('dict1元素个数:',len(dict1))
	print('dict2元素个数:',len(dict2))
	while(True):
		# 输入给定语句
		test = input()
		# 用+1法作为数据平滑技术，预测给定语句的语言概率
		PlusOne(test)