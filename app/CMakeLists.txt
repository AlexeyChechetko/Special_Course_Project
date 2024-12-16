cmake_minimum_required(VERSION 3.10)
project(Project
	VERSION 1.0
	DESCRIPTION "Project: price option"
)

# Указываем, что мы будем собирать три исполняемых файла
add_subdirectory(Commander)
add_subdirectory(Loader)
add_subdirectory(DBManager)
add_subdirectory(OptionPricer)
