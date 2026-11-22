# setup.sample.py

from setuptools import find_packages, setup

package_name = '2_srvmsg'   # 자동 수정

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='you@example.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'add_ints_client = 2_srvmsg.add_ints_client:main',
            'add_ints_server = 2_srvmsg.add_ints_server:main',
            'move_robot_client = 2_srvmsg.move_robot_client:main',
            'move_robot_server = 2_srvmsg.move_robot_server:main'
        ],
    },
)
