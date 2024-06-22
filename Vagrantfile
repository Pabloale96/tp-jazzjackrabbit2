# Vagrantfile

Vagrant.configure("2") do |config|
    # Usar Ubuntu Focal como base
    config.vm.box = "ubuntu/focal64"
  
    config.vm.provider "virtualbox" do |vb|
      vb.memory = "2048"
      vb.cpus = 2
    end
  
    config.vm.provision "shell", path: "installer.sh"
  end
