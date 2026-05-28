# LavaDev OS - Development Roadmap

## 📊 Project Status: Alpha (v0.1.0)

### ✅ Completed (Phase 1)
- [x] Multi-architecture support structure (x86, x64, ARM)
- [x] Bootloader stubs for all architectures
- [x] Console/VGA driver
- [x] Memory management framework
- [x] Process scheduler (round-robin)
- [x] Interrupt handling system
- [x] Virtual file system framework
- [x] Build system (Makefile)
- [x] Debug tools (GDB/QEMU scripts)

### 🔄 In Progress (Phase 2)
- [ ] x64 Paging implementation
- [ ] Physical memory allocator
- [ ] Kernel heap allocator (SLAB)
- [ ] Extended interrupt handlers (PIC/APIC)
- [ ] Basic system calls
- [ ] ext4 file system driver

### ⏳ Planned (Phase 3-5)
- [ ] Multi-core support (SMP)
- [ ] Advanced scheduling (CFS)
- [ ] Networking stack (TCP/IP)
- [ ] User space execution
- [ ] Module system
- [ ] Device hot-plugging

## 🎯 Milestones

| Milestone | Timeline | Status |
|-----------|----------|--------|
| Bootable kernel (x64) | Week 1 | 🔄 In Progress |
| Memory paging | Week 2 | ⏳ Planned |
| Process execution | Week 3 | ⏳ Planned |
| File system mount | Week 4 | ⏳ Planned |
| Basic shell | Week 6 | ⏳ Planned |

## 📝 Contributing Guidelines

### Code Style
- Use UNIX line endings (LF)
- 4-space indentation (C) / 4 spaces (Assembly)
- Max line length: 100 characters
- Include meaningful comments

### Commit Message Format
```
[TAG] Brief description

Longer explanation if needed.

Fixes: #issue_number
```

Tags:
- `✨` - New feature
- `🐛` - Bug fix
- `💾` - Memory/storage changes
- `⚡` - Performance improvement
- `📖` - Documentation
- `🔨` - Build/tooling
- `🎨` - Code cleanup

### Testing
- Test on all supported architectures
- Use GDB for debugging
- Document test cases
- Include unit tests when possible

## 🤝 Getting Started

### For Developers
1. Fork the repository
2. Create feature branch: `git checkout -b feature/name`
3. Make changes following code style
4. Test on x64: `make ARCH=x64 && ./scripts/qemu.sh x64`
5. Commit with proper tags
6. Create pull request

### For Users
1. Clone repository: `git clone https://github.com/gcode4421-oss/lavadev.git`
2. Build: `make ARCH=x64`
3. Run: `./scripts/qemu.sh x64`

## 📚 Documentation Structure

- `docs/ARCHITECTURE.md` - System design
- `docs/SYSCALLS.md` - System call reference
- `docs/DRIVERS.md` - Driver development guide
- `docs/CONTRIBUTING.md` - Contribution guidelines
- `docs/design/` - Design documents

## 🔗 External Resources

- [OSDev.org](https://wiki.osdev.org)
- [Linux Kernel Docs](https://www.kernel.org/doc)
- [Intel Manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)
- [ARM Docs](https://developer.arm.com)

## 📞 Support

- GitHub Issues: Bug reports and feature requests
- Discussions: General questions and ideas
- Email: gcode4421@gmail.com

---

**Last Updated**: 2026-05-28 | **Maintained by**: gcode4421-oss