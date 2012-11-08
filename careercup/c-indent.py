def indent(in_stream,out_stream):
	indent=0;
	def split(line):
		return list(x.strip() for x in line.split(';'))
	def printsplit(line):
		lines = split(line)
		if len(lines)==1 and lines[0].strip()=='':
			return
		print lines
		if lines[-1].strip()=='':
			for line in lines[:-1]:
				print >>out_stream, indent*' '+line+";"
		else:
			for line in lines[:-1]:
				print>>out_stream, indent*' '+line+";"
			print>>out_stream, indent*' '+lines[-1]
	for line in in_stream:
		line2=line
		while(line2.strip()!=''):
			l=line2.find('{')
			r=line2.find('}')
			if l==-1 and r==-1:
				printsplit(line2)
				line2="";
			elif l!=-1 and (r==-1 or l<r):
				printsplit(line2[:l])
				print>>out_stream, indent*' '+"{"
				indent+=4
				line2=line2[l+1:]
			elif r!=-1 and (l==-1 or r<l):
				printsplit(line2[:r])
				indent-=4
				print>>out_stream, indent*' '+"}"
				line2=line2[r+1:]


if __name__ == '__main__':
	with open('input.c') as in_file:
		with open('output.c','w') as out_file:
			indent(in_file,out_file)
