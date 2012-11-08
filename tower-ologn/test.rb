class GolombSeq
  def initialize
    init
  end
  
  def init
    @sig = [1, 3]
    @idx = 1
  end

  def g n
    while @sig.last < n
      @sig << @sig.last + search_gn(@idx + @sig.size)
      return (@idx + @sig.size - 1) if @sig.last >= n
    end
    return gn n
  rescue => e
    puts ">>> SIG SIZE : #{@sig.size} / n : #{n}"
    p e
    return 0
  end
  
  def sg3 n
    sum = 0
    (1...n).each do |x|
      sum += g(x**3)
    end
    sum
  end
    
  private
  def search_gn n
    while @sig.first < n
      @idx += 1
      @sig.shift
    end
    @idx
  end
  
  def gn n
    @sig.size.times {|x|
      return @idx + x if @sig[x] >= n
    }
  end
  
end

seq = GolombSeq.new

require "benchmark"
Benchmark.bm do |rep|
  #rep.report {puts seq.g 1000}
  #seq.init
  #rep.report {puts seq.g 1000000}
  #seq.init
  #rep.report {puts seq.sg3 1000}
  #seq.init
  rep.report {puts seq.sg3 1000}
end