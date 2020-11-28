from conans import ConanFile, CMake

class ConanDependencies(ConanFile):

    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "qt", "virtualrunenv"

    default_options = {}

    def requirements(self):
        # self.requires("gtest/1.10.0")
        self.requires("qt/5.15.2@bincrafters/stable")

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='lib', src='lib')
        self.copy('*', dst='libexec', src='libexec')
        self.copy('*', dst='plugins', src='plugins')
        self.copy('*', dst='qml', src='qml')
        self.copy('*', dst='translations', src='translations')
        self.copy('*', dst='resources', src='resources')
        self.copy("license*", dst="licenses", folder=True, ignore_case=True)