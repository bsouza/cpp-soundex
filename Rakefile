class Raker
  
  include FileUtils

  def initialize
  	save_root_path
  end
  
  private
  
  	def save_root_path
  	  @root_path = Dir.pwd
  	end
    
    def goto_build_dir
      Dir.mkdir build_dir if !(File.exist? build_dir)
      Dir.chdir build_dir 
    end
    
    def build_dir
      "#{@root_path}/build"
    end
  
  public
  
    def compile
      puts 'compiling...'
      goto_build_dir
      system 'cmake ..'
      system 'make'
    end
    
    def test
      puts 'executing tests...'
      goto_build_dir
      system './test'
    end
    
    def clean
      puts 'clean build directory...'
      rm_rf build_dir
    end
	
end

raker = Raker.new

task :default => [:test]

task :make do
  raker.compile  
end

task :clean do
  raker.clean
end

task :cm => [ :clean, :make ] do 
end

task :test => [ :cm ] do
  raker.test
end