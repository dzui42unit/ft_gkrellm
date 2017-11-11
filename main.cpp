#include <iostream>
#include <unistd.h>
#include <sys/utsname.h>
#include <cassert>
#include <fstream>

#define BUFF_NAME 	256
#define BUFF_SIZE	1024


//	int uname(struct utsname *buf);

//	utsname	info;

//	uname(&info);

//	std::cout << "sysname: " << info.sysname << std::endl;
//	std::cout << "nodename: " << info.nodename << std::endl;
//	std::cout << "release: " << info.release << std::endl;
//	std::cout << "version: " << info.version << std::endl;
//	std::cout << "machine: " << info.machine << std::endl;

//	unsigned 	buflen = 0;
//	char 		line[BUFF_NAME];
//	char 		buf[BUFF_SIZE];
//
//
//	FILE *sw_vers = popen("sw_vers", "r");
//	while (fgets(line, sizeof(line), sw_vers) != NULL)
//	{
//	int l = snprintf(buf + buflen, sizeof(buf) - buflen, "%s", line);
//	buflen += l;
//	assert(buflen < sizeof(buf));
//	}
//	std::cout << buf << std::endl;
//	pclose(sw_vers);



int		main(void)
{
	// HOST_NAME / USER_NAME MODULE / SYS INFO / CUR TIME

	std::string		os_info;
	std::string		proc_info;
	char 			host_name[BUFF_NAME];
	char 			user_name[BUFF_NAME];
	char 			buff[BUFF_SIZE];
	FILE			*pipe;
	time_t 			time;
	char 			*dt;

	// PRINT HOST_NAME / USER_NAME

	gethostname(host_name, BUFF_NAME);
	std::cout << std::endl <<  host_name << std::endl;
	getlogin_r(user_name, BUFF_NAME);
	std::cout << user_name << std::endl << std::endl;

	// GET OS NAME / VERSION / BUILD

	pipe = popen("sw_vers", "r");
	while (!feof(pipe))
	{
		if (fgets(buff, BUFF_SIZE, pipe) != NULL)
			os_info += buff;
	}
	pclose(pipe);
	std::cout << os_info << std::endl;

	// GET CURRENT TIME

	time = std::time(0); 	// getting current time
	dt = ctime(&time); 	// converting time to a string
	std::cout << dt << std::endl;

	// GET CPU NAME / CLOCK SPEED

	pipe = popen("sysctl -n machdep.cpu.brand_string", "r");
	while (!feof(pipe))
	{
		if (fgets(buff, BUFF_SIZE, pipe) != NULL)
			proc_info += buff;
	}
	pclose(pipe);
	std::cout << proc_info << std::endl;

	// GET NUMBER OF CORES

	int numCPU = sysconf(_SC_NPROCESSORS_ONLN);

	std::cout << "Cores: " << numCPU << std::endl << std::endl;

	return (0);
}
