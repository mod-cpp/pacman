from conans import ConanFile, CMake

class ConanDependencies(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_find_package"
    default_options = {}

    def requirements(self):
        self.requires("gtest/1.10.0")

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='lib', src='lib')
        self.copy("license*", dst="licenses", folder=True, ignore_case=True)
