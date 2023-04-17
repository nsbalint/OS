#!/bin/bash
 
# Set colors
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
 
# Check if connected to the internet
ping -q -w 1 -c 1 8.8.8.8 &> /dev/null && connected=true || connected=false
 
# Display system information
echo -e "${RED}----- System Information -----${NC}"
echo -e "${GREEN}Internet:${NC} $([ $connected == true ] && echo "Connected" || echo "Disconnected")"
echo -e "${GREEN}OS Type:${NC} $(uname -o)"
echo -e "${GREEN}Server Type:${NC} $(uname -m)"
echo -e "${GREEN}Distribution:${NC} $(lsb_release -d | awk '{print $2,$3,$4}')"
echo -e "${GREEN}Architecture:${NC} $(uname -i)"
echo -e "${GREEN}Kernel Release:${NC} $(uname -r)"
echo -e "${GREEN}Hostname:${NC} $(hostname)"
echo -e "${GREEN}Internal IP:${NC} $(hostname -I)"
echo -e "${GREEN}Logged In Users:${NC} $(who | awk '{print $1}' | uniq | tr '\n' ', ')"
echo -e "${GREEN}RAM Usage:${NC} $(free -h | awk '/^Mem:/ {print $3 "/" $2 " used (" $4 " free)"}')"
echo -e "${GREEN}Swap Usage:${NC} $(free -h | awk '/^Swap:/ {print $3 "/" $2 " used (" $4 " free)"}')"
echo -e "${GREEN}Disk Usage:${NC}"
df -h | awk '{print $1,$2,$3,$4,$5,$6}' | while read -r disk; do
    echo -e "   ${GREEN}$disk${NC}"
done
echo -e "${GREEN}Disk Details:${NC}"
lsblk | awk '/disk/ {print $1,$4}' | while read -r disk; do
    echo -e "   ${GREEN}$disk${NC}"
done
echo -e "${GREEN}Load Average:${NC} $(uptime | awk -F'[a-z]:' '{print $2}')"
echo -e "${GREEN}System Uptime:${NC} $(uptime -p | awk '{print $2,$3,$4,$5}')"
 
# Reset terminal color
echo -e "${NC}"
 
